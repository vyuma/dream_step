'use client';

import { useState, useEffect } from 'react';
import { useRouter } from 'next/navigation';

type Question = {
  id: number;
  text: string;
};

type Answers = {
  [key: number]: string;
};

export default function Questions() {
  const router = useRouter();
  const [dream, setDream] = useState<string>('');
  const [questions, setQuestions] = useState<Question[]>([]);
  const [answers, setAnswers] = useState<Answers>({});
  const [loading, setLoading] = useState(true);
  const [dreamAnalysis, setDreamAnalysis] = useState<string | null>(null);

  useEffect(() => {
    const storedDream = sessionStorage.getItem('dream');
    if (storedDream) {
      setDream(storedDream);
      setTimeout(() => {
        const mockQuestions = [
          { id: 1, text: "その夢をどのくらいの期間で実現したいですか？" },
          { id: 2, text: "その夢を実現するためにすでに行動していることはありますか？" },
          { id: 3, text: "その夢を持った理由や原点は何ですか？" },
          { id: 4, text: "夢の実現に必要なスキルや資源は何だと思いますか？" },
          { id: 5, text: "この夢に対して不安や障害に感じていることはありますか？" }
        ];
        setQuestions(mockQuestions);
        setLoading(false);
      }, 1500);
    } else {
      router.push('/');
    }
  }, [router]);

  const handleAnswerChange = (id: number, value: string) => {
    setAnswers(prev => ({ ...prev, [id]: value }));
  };

  const handleSave = () => {
    sessionStorage.setItem('answers', JSON.stringify(answers));
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
                    {questions.map((question) => (
                      <div key={question.id} className="flex flex-col bg-purple-800 bg-opacity-20 border border-purple-400 border-opacity-20 p-4 rounded-lg">
                        <p className="text-white mb-2">{question.text}</p>
                        <textarea
                          className="w-full p-2 rounded-md bg-purple-900 bg-opacity-50 text-white border border-purple-300 focus:outline-none focus:ring-2 focus:ring-pink-400"
                          value={answers[question.id] || ''}
                          onChange={(e) => handleAnswerChange(question.id, e.target.value)}
                          rows={3}
                        />
                      </div>
                    ))}
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
