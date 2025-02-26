'use client';

import { useState, useEffect } from 'react';
import { useRouter } from 'next/navigation';

export default function Result() {
  const router = useRouter();
  const [dream, setDream] = useState<string>('');
  const [answers, setAnswers] = useState<Record<number, string>>({});
  const [loading, setLoading] = useState(true);
  const [dreamAnalysis, setDreamAnalysis] = useState('');

  useEffect(() => {
    // セッションストレージから夢と回答を取得
    const storedDream = sessionStorage.getItem('dream');
    const storedAnswers = sessionStorage.getItem('answers');
    
    if (storedDream) {
      setDream(storedDream);
    } else {
      // 夢が設定されていない場合はトップページに戻す
      router.push('/');
      return;
    }
    
    if (storedAnswers) {
      setAnswers(JSON.parse(storedAnswers));
    } else {
      // 回答がない場合はトップページに戻す
      router.push('/');
      return;
    }

    // 実際のAPIを呼び出す代わりに、仮のデータを使用
    // 本番環境ではAI APIを使ってフィードバックを生成する
    setTimeout(() => {
      setDreamAnalysis(`あなたの「${storedDream}」という夢について、具体的な計画を立てるための情報が集まりました。短期的な目標と長期的な目標を段階的に設定し、必要なスキルを習得しながら、着実に前進することが重要です。まずは情報収集と小さな一歩から始めましょう。あなたの熱意と具体的な行動計画があれば、この夢は実現可能です。必要なリソースを確保し、周囲のサポートを得ながら、一歩ずつ前進していきましょう。`);
      setLoading(false);
    }, 2000);
  }, [router]);

  const handleGenerateTasks = () => {
    // タスク生成ページへ遷移する予定（今回は作成範囲外）
    alert('タスク生成機能は開発中です。');
  };

  return (
    <div className="min-h-screen bg-gradient-to-br from-purple-900 via-purple-700 to-pink-600">
      <main className="container mx-auto px-4 py-16">
        <div className="max-w-2xl mx-auto">
          <div className="text-center mb-8">
            <h1 className="text-3xl font-bold mb-2 text-white">夢の分析結果</h1>
            <p className="text-lg text-purple-100">AIによる分析と次のステップの提案</p>
          </div>

          <div className="bg-white bg-opacity-10 backdrop-blur-lg rounded-xl p-8 shadow-2xl border border-purple-300 border-opacity-20">
            {loading ? (
              <div className="flex flex-col justify-center items-center py-12">
                <div className="animate-spin rounded-full h-12 w-12 border-t-2 border-b-2 border-pink-500 mb-4"></div>
                <p className="text-purple-100">あなたの夢を分析中...</p>
              </div>
            ) : (
              <>
                <div className="mb-8">
                  <h2 className="text-xl font-medium text-white mb-4">あなたの夢：</h2>
                  <p className="text-purple-100 bg-purple-800 bg-opacity-30 p-4 rounded-lg mb-6">{dream}</p>
                  
                  <h2 className="text-xl font-medium text-white mb-4">夢の分析と具体化：</h2>
                  <div className="bg-purple-800 bg-opacity-20 p-6 rounded-lg border border-purple-400 border-opacity-20">
                    <p className="text-white leading-relaxed">{dreamAnalysis}</p>
                  </div>
                </div>

                <div className="flex justify-end">
                  <button
                    onClick={handleGenerateTasks}
                    className="px-8 py-3 bg-gradient-to-r from-pink-500 to-purple-600 text-white font-medium rounded-full shadow-lg hover:from-pink-600 hover:to-purple-700 focus:outline-none focus:ring-2 focus:ring-pink-500 focus:ring-offset-2 transform transition hover:-translate-y-1"
                  >
                    タスク生成
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