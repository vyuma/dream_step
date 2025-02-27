'use client';

import { useState, useEffect } from 'react';
import { useRouter } from 'next/navigation';

import  AnswerText from '../components/AnswerText';
import {Question} from  '../components/AnswerText'


type Question = {
  Question: string;
  Answer: string;
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
  const [processingNext, setProcessingNext] = useState(false);
  const [dreamAnalysis, setDreamAnalysis] = useState<string | null>(null);

  useEffect(() => {
    if (typeof window !== 'undefined') {
      const storedDream = sessionStorage.getItem('dream');
      const storedQuestionData = sessionStorage.getItem('questionData');
      
      if (storedDream) {
        setDream(storedDream);
        
        if (storedQuestionData) {
          try {
            const data = JSON.parse(storedQuestionData);
            console.log("セッションストレージから読み込んだデータ:", data);
            
            if (data && data.Question && Array.isArray(data.Question)) {
              setQuestions(data.Question);
              
              // 初期回答をLLMの回答に設定
              const initialAnswers: {[key: number]: string} = {};
              data.Question.forEach((q: any, index: number) => {
                initialAnswers[index] = q.Anser || '';
              });
              setAnswers(initialAnswers);
            } else {
              console.error("予期しないデータ形式:", data);
            }
          } catch (e) {
            console.error("JSONパースエラー:", e);
          }
        } else {
          console.error("質問データがセッションストレージにありません");
        }
        
        setLoading(false);
      } else {
        // 夢のデータがない場合はホーム画面に戻る
        console.log("夢データがセッションストレージにないため、ホーム画面に戻ります");
        router.push('/');
      }
    }
  }, [router]);

  const handleAnswerChange = (id: number, value: string) => {
    setAnswers(prev => ({ ...prev, [id]: value }));
  };

  const handleSave = () => {
    // 回答をanswerから取得して、{Question:質問, Answer:回答}の形式に変換
    const formattedQA = {
      "Answer": questions.map((q,index)=> {
        return {
          "Question": q.Question,
          "Answer": answers[index]
        }
      })
    }


    sessionStorage.setItem('answers', JSON.stringify(answers));

    // APIに回答する。
    const DreamSummary = async () => {
      setLoading(true);
      try {
        const res = await fetch(process.env.NEXT_PUBLIC_API_URL + 'yume_summary', {
          method: 'POST',
          headers: { 'Content-Type': 'application/json' },
          body: JSON.stringify(formattedQA),
        });

        res.json().then((data: { Analysis: string }) => {
          setDreamAnalysis(data.Analysis);
        }
        );
        setLoading(false);
      } catch (error) {
        console.error("Error fetching Yume data:", error);
        return null;
      }
    }
    DreamSummary();
    
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
                        <AnswerText 
                          key={index} 
                          question={question} 
                          index={index} 
                          handleAnswerChange={handleAnswerChange}
                        />

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
                    disabled={questions.length === 0 || processingNext}
                  >
                    {processingNext ? (
                      <div className="flex items-center">
                        <div className="animate-spin rounded-full h-4 w-4 border-t-2 border-b-2 border-white mr-2"></div>
                        処理中...
                      </div>
                    ) : (
                      "次へ進む"
                    )}
                  </button>
                </div>

                {processingNext && !dreamAnalysis && (
                <div className="mt-8 flex justify-center items-center py-8">
                  <div className="flex flex-col items-center">
                    <div className="animate-spin rounded-full h-12 w-12 border-t-2 border-b-2 border-pink-500 mb-4"></div>
                    <p className="text-white">夢の分析を生成しています...</p>
                  </div>
                </div>
              )}

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