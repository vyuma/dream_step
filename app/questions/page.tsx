"use client";

import { useState, useEffect } from "react";
import { useRouter } from "next/navigation";
import QAItem from "./QAItem";

type Question = { id: number; text: string };
type Answers = { [key: number]: string };

// ローディンぐ（仮）
function LoadingSpinner() {
  return (
    <div className="flex justify-center py-6">
      <div className="animate-spin h-10 w-10 border-t-2 border-gray-600 rounded-full"></div>
    </div>
  );
}

export default function Questions() {
  const router = useRouter();
  const [dream, setDream] = useState("");
  const [questions, setQuestions] = useState<Question[]>([]);
  const [answers, setAnswers] = useState<Answers>({});
  const [loading, setLoading] = useState(true);
  const [analysis, setAnalysis] = useState<string | null>(null);

  useEffect(() => {
    const storedDream = sessionStorage.getItem("dream");
    if (!storedDream) return router.push("/");

    setDream(storedDream);
    setTimeout(() => {
      setQuestions([
        { id: 1, text: "その夢をどのくらいの期間で実現したいですか？" },
        {
          id: 2,
          text: "その夢を実現するためにすでに行動していることはありますか？",
        },
        { id: 3, text: "その夢を持った理由や原点は何ですか？" },
        { id: 4, text: "夢の実現に必要なスキルや資源は何だと思いますか？" },
        {
          id: 5,
          text: "この夢に対して不安や障害に感じていることはありますか？",
        },
      ]);
      setLoading(false);
    }, 1500);
  }, [router]);

  const handleAnswerChange = (id: number, value: string) => {
    setAnswers((prev) => ({ ...prev, [id]: value }));
  };

  const handleSave = () => {
    sessionStorage.setItem("answers", JSON.stringify(answers));
    setAnalysis(
      "あなたの夢について具体的な計画を立てるための情報が集まりました。短期的な目標と長期的な目標を段階的に設定し、必要なスキルを習得しながら、着実に前進することが重要です。まずは情報収集と小さな一歩から始めましょう。"
    );
  };

  return (
    <div className="">
      {loading ? (
        <LoadingSpinner />
      ) : (
        <>
          <div className="">
            <div className="bg-rose-400 text-white text-center py-6 h-64 w-full">
              <h1 className="text-4xl  font-bold">- あなたの夢を深掘り -</h1>
              <div className="mt-4 mx-auto bg-white text-gray-700 font-semibold p-4 w-3/4 h-32 flex items-center justify-center rounded-md">
                <p className="text-lg text-center">{dream}</p>
              </div>
            </div>

            <div className="space-y-4 w-3/5 mx-auto mt-4">
              <div className="">
                {questions.map((q) => (
                  <QAItem
                    key={q.id}
                    question={q}
                    answer={answers[q.id] || ""}
                    onChange={handleAnswerChange}
                  />
                ))}
              </div>
              <button
                onClick={handleSave}
                className="px-16 py-4 bg-rose-400 text-white font-bold rounded-full mx-auto block mt-8"
              >
                回答を生成する
              </button>
              {analysis && (
                <div className="my-4 p-4 bg-gray-200 rounded-lg">
                  <h2 className="text-gray-700 font-bold">
                    夢の分析と具体化：
                  </h2>
                  <p className="text-gray-600 mt-2">{analysis}</p>
                </div>
              )}
            </div>
          </div>
        </>
      )}
    </div>
  );
}
