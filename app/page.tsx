'use client';

import { useState } from 'react';
import { useRouter } from 'next/navigation';

export default function Home() {
  const [dream, setDream] = useState('');
  const router = useRouter();

  const handleSubmit = (e: React.FormEvent) => {
    e.preventDefault();
    if (dream.trim()) {
      // App Routerではクエリパラメータの代わりにURLパスかSessionStorageを使う
      sessionStorage.setItem('dream', dream);
      router.push('/questions');
    }
  };

  return (
    <div className="min-h-screen bg-gradient-to-br from-purple-900 via-purple-700 to-pink-600">
      <main className="container mx-auto px-4 py-16">
        <div className="max-w-2xl mx-auto">
          <div className="text-center mb-12">
            <h1 className="text-4xl font-bold mb-4 text-white">Dream Step</h1>
            <p className="text-xl text-purple-100">AIと共に、夢への道筋を明確にしましょう</p>
          </div>

          <div className="bg-white bg-opacity-10 backdrop-blur-lg rounded-xl p-8 shadow-2xl border border-purple-300 border-opacity-20">
            <form onSubmit={handleSubmit}>
              <div className="mb-8">
                <label htmlFor="dream" className="block text-xl font-medium mb-4 text-white">
                  あなたの夢を教えてください
                </label>
                <textarea
                  id="dream"
                  rows={5}
                  className="w-full p-4 rounded-lg bg-purple-800 bg-opacity-30 text-white placeholder-purple-300 border border-purple-400 border-opacity-30 focus:ring-2 focus:ring-pink-500 focus:border-transparent"
                  placeholder="例: 自分のカフェを開きたい、世界一周旅行をしたい..."
                  value={dream}
                  onChange={(e) => setDream(e.target.value)}
                  required
                />
              </div>


              
              <div className="flex justify-end">
                <button
                  type="submit"
                  className="px-8 py-3 bg-gradient-to-r from-pink-500 to-purple-600 text-white font-medium rounded-full shadow-lg hover:from-pink-600 hover:to-purple-700 focus:outline-none focus:ring-2 focus:ring-pink-500 focus:ring-offset-2 transform transition hover:-translate-y-1"
                >
                  次へ進む
                </button>
              </div>
            </form>
          </div>
        </div>
      </main>
    </div>
  );
}