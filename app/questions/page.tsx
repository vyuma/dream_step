'use client';

import { useState, useEffect } from 'react';
import { useRouter } from 'next/navigation';

type Question = {
  Question: string;
  Anser: string; // APIのレスポンスに合わせて"Anser"というスペルにする
};

export default function Questions() {
  const router = useRouter();
  const [dream, setDream] = useState<string>('');
  const [questions, setQuestions] = useState<Question[]>([]);
  const [answers, setAnswers] = useState<{[key: number]: string}>({});
  const [loading, setLoading] = useState(true);
  const [dreamAnalysis, setDreamAnalysis] = useState<string | null>(null);

  useEffect(() => {
    if (typeof window !== 'undefined') {
      const storedDream = sessionStorage.getItem('yume_prompt');
      if (storedDream) {
        setDream(storedDream);
        
        // サーバーに質問を取得するリクエストを送信
        const requestBody = { yume_prompt: storedDream };
        console.log("送信リクエスト:", requestBody);
        
        fetch("http://localhost:8000/api/generate_yume_question", {
          method: "POST",
          headers: { "Content-Type": "application/json" },
          body: JSON.stringify(requestBody)
        })
          .then(async (res) => {
            console.log("レスポンスステータス:", res.status);
            const responseText = await res.text(); // テキストとして読み込み
            console.log("レスポンス本文:", responseText);
            
            try {
              // 有効なJSONかどうか確認してからパース
              const data = responseText ? JSON.parse(responseText) : {};
              if (!res.ok) {
                console.error("APIエラー詳細:", data);
                throw new Error(`API error: ${res.status}`);
              }
              return data;
            } catch (e) {
              console.error("JSONパースエラー:", e);
              throw new Error("Invalid JSON response");
            }
          })
          .then((data) => {
            // バックエンドから返されるデータ構造に合わせる
            if (data.Question && Array.isArray(data.Question)) {
              setQuestions(data.Question);
              
              // 初期回答をLLMの回答に設定
              const initialAnswers: {[key: number]: string} = {};
              data.Question.forEach((q, index) => {
                initialAnswers[index] = q.Anser;
              });
              setAnswers(initialAnswers);
            } else {
              console.error("Unexpected data format:", data);
            }
            setLoading(false);
          })
          .catch((error) => {
            console.error("Error fetching questions:", error);
            setLoading(false);
          });
      } else {
        router.push('/');
      }
    }
  }, [router]);

  const handleAnswerChange = (index: number, value: string) => {
    setAnswers(prev => ({ ...prev, [index]: value }));
  };

  const handleSave = () => {
    // 回答をセッションストレージに保存
    sessionStorage.setItem('answers', JSON.stringify(answers));
    
    // 夢の分析文を設定（実際にはAPIから取得するべき）
    setDreamAnalysis("あなたの夢について具体的な計画を立てるための情報が集まりました。短期的な目標と長期的な目標を段階的に設定し、必要なスキルを習得しながら、着実に前進することが重要です。まずは情報収集と小さな一歩から始めましょう。あなたの熱意と具体的な行動計画があれば、この夢は実現可能です。");
  };

  return (
    <div className="min-h-screen bg-gradient-to-br from-purple-900 via-purple-700 to-pink-600">
      <main className="container mx-auto px-4 py-16">
        <div className="max-w-3xl mx-auto">
          <div className="text-center mb-8">
            <h1 className="text-3xl font-bold mb-2 text-white">あなたの夢を深掘りします</h1>
            <p className="text-lg text-purple-100">以下の質問に答えることで、夢への理解が深まります</p>
          </div>

          <div className="bg-white bg-opacity-10 backdrop-blur-lg rounded-xl p-8 shadow-2xl border border-purple-300 border-opacity-20">
            {loading ? (
              <div className="flex justify-center items-center py-12">
                <div className="animate-spin rounded-full h-12 w-12 border-t-2 border-b-2 border-pink-500"></div>
              </div>
            ) : (
              <>
                <div className="mb-6">
                  <h2 className="text-xl font-medium text-white mb-4">あなたの夢：</h2>
                  <p className="text-purple-100 bg-purple-800 bg-opacity-30 p-4 rounded-lg">{dream}</p>
                </div>

                <div className="mb-8">
                  <h2 className="text-xl font-medium text-white mb-4">以下の質問に回答してください：</h2>
                  <div className="space-y-4">
                    {questions && questions.length > 0 ? (
                      questions.map((question, index) => (
                        <div key={index} className="flex flex-col bg-purple-800 bg-opacity-20 border border-purple-400 border-opacity-20 p-4 rounded-lg">
                          <p className="text-white mb-2">{question.Question}</p>
                          <textarea
                            className="w-full p-2 rounded-md bg-purple-900 bg-opacity-50 text-white border border-purple-300 focus:outline-none focus:ring-2 focus:ring-pink-400"
                            value={answers[index] || question.Anser}
                            onChange={(e) => handleAnswerChange(index, e.target.value)}
                            rows={3}
                          />
                        </div>
                      ))
                    ) : (
                      <p className="text-white">質問が読み込めませんでした。もう一度お試しください。</p>
                    )}
                  </div>
                </div>

                <div className="flex justify-end">
                  <button
                    onClick={handleSave}
                    className="px-8 py-3 bg-gradient-to-r from-pink-500 to-purple-600 text-white font-medium rounded-full shadow-lg hover:from-pink-600 hover:to-purple-700 focus:outline-none focus:ring-2 focus:ring-pink-500 focus:ring-offset-2 transform transition hover:-translate-y-1"
                  >
                    回答を生成する
                  </button>
                </div>

                {dreamAnalysis && (
                  <div className="mt-8 p-6 bg-purple-800 bg-opacity-20 rounded-lg border border-purple-400 border-opacity-20 relative">
                    <h2 className="text-xl font-medium text-white mb-4">夢の分析と具体化：</h2>
                    <p className="text-white leading-relaxed">{dreamAnalysis}</p>
                    <div className="flex justify-end mt-4">
                      <button
                        className="px-8 py-3 bg-gradient-to-r from-pink-500 to-purple-600 text-white font-medium rounded-full shadow-lg hover:from-pink-600 hover:to-purple-700 focus:outline-none focus:ring-2 focus:ring-pink-500 focus:ring-offset-2 transform transition hover:-translate-y-1"
                      >
                        タスクを生成
                      </button>
                    </div>
                  </div>
                )}
              </>
            )}
          </div>
        </div>
      </main>
    </div>
  );
}