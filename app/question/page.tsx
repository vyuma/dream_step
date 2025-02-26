'use client';

import { useState, useEffect } from 'react';
import { useRouter } from 'next/navigation';

type Question = {
  id: number;
  text: string;
};

export default function Questions() {
  const router = useRouter();
  const [dream, setDream] = useState<string>('');
  const [questions, setQuestions] = useState<Question[]>([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    // セッションストレージから夢を取得
    const storedDream = sessionStorage.getItem('dream');
    if (storedDream) {
      setDream(storedDream);
      
      // 実際のAPIを呼び出す代わりに、仮のデータを使用
      // 本番環境ではAI APIを使って質問を生成する
      setTimeout(() => {
        setQuestions([
          { id: 1, text: "その夢をどのくらいの期間で実現したいですか？" },
          { id: 2, text: "その夢を実現するためにすでに行動していることはありますか？" },
          { id: 3, text: "その夢を持った理由や原点は何ですか？" },
          { id: 4, text: "夢の実現に必要なスキルや資源は何だと思いますか？" },
          { id: 5, text: "この夢に対して不安や障害に感じていることはありますか？" }
        ]);
        setLoading(false);
      }, 1500);
    } else {
      // 夢が設定されていない場合はトップページに戻す
      router.push('/');
    }
  }, [router]);

  const handleContinue = () => {
    // セッションストレージに質問を保存（実際の実装ではバックエンドに保存するのが一般的）
    sessionStorage.setItem('questions', JSON.stringify(questions));
    router.push('/question-detail/1');
  };

  return (
    <div className="min-h-screen bg-gradient-to-br from-purple-900 via-purple-700 to-pink-600">
      <main className="container mx-auto px-4 py-16">
        <div className="max-w-2xl mx-auto">
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
                  <h2 className="text-xl font-medium text-white mb-4">以下の質問に回答していきましょう：</h2>
                  <ul className="space-y-4">
                    {questions.map((question) => (
                      <li 
                        key={question.id} 
                        className="p-4 rounded-lg bg-purple-800 bg-opacity-20 border border-purple-400 border-opacity-20"
                      >
                        <p className="text-white">{question.text}</p>
                      </li>
                    ))}
                  </ul>
                </div>

                <div className="flex justify-end">
                  <button
                    onClick={handleContinue}
                    className="px-8 py-3 bg-gradient-to-r from-pink-500 to-purple-600 text-white font-medium rounded-full shadow-lg hover:from-pink-600 hover:to-purple-700 focus:outline-none focus:ring-2 focus:ring-pink-500 focus:ring-offset-2 transform transition hover:-translate-y-1"
                  >
                    質問に回答する
                  </button>
                </div>
              </>
            )}
          </div>
        </div>
      </main>
    </div>
  );
}