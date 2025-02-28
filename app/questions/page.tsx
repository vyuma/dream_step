"use client";

import { useState, useEffect } from "react";
import { useRouter } from "next/navigation";
import QAItem from "./QAItem";

type Answers = {
  [key: number]: string;
};
type Question = {
  Question: string;
  Answer: string;
};
function LoadingSpinner() {
  return (
    <div className="flex justify-center py-6">
      <div className="animate-spin h-10 w-10 border-t-2 border-gray-600 rounded-full"></div>
    </div>
  );
}

export default function Questions() {
  const router = useRouter();
  const [dream, setDream] = useState<string>("");
  const [questions, setQuestions] = useState<Question[]>([]);
  const [answers, setAnswers] = useState<Answers>({});
  const [loading, setLoading] = useState(true);
  const [processingNext, setProcessingNext] = useState(false);
  const [dreamAnalysis, setDreamAnalysis] = useState<string | null>(null);

  useEffect(() => {
    if (typeof window !== "undefined") {
      const storedDream = sessionStorage.getItem("dream");
      const storedQuestionData = sessionStorage.getItem("questionData");

      if (storedDream) {
        setDream(storedDream);

        if (storedQuestionData) {
          try {
            const data = JSON.parse(storedQuestionData);
            console.log("セッションストレージから読み込んだデータ:", data);

            if (data && data.Question && Array.isArray(data.Question)) {
              setQuestions(data.Question);

              // 初期回答をLLMの回答に設定
              const initialAnswers: { [key: number]: string } = {};
              data.Question.forEach((q: any, index: number) => {
                initialAnswers[index] = q.Anser || "";
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
        console.log(
          "夢データがセッションストレージにないため、ホーム画面に戻ります"
        );
        router.push("/");
      }
    }
  }, [router]);

  const handleAnswerChange = (id: number, value: string) => {
    setAnswers((prev) => ({ ...prev, [id]: value }));
  };

  const handleSave = () => {
    // 回答をanswerから取得して、{Question:質問, Answer:回答}の形式に変換
    const formattedQA = {
      Answer: questions.map((q, index) => {
        return {
          Question: q.Question,
          Answer: answers[index],
        };
      }),
    };

    sessionStorage.setItem("answers", JSON.stringify(answers));

    // APIに回答する。
    const DreamSummary = async () => {
      setLoading(true);
      try {
        const res = await fetch(
          process.env.NEXT_PUBLIC_API_URL + "api/yume_summary",
          {
            method: "POST",
            headers: { "Content-Type": "application/json" },
            body: JSON.stringify(formattedQA),
          }
        );

        res.json().then((data: { Analysis: string }) => {
          setDreamAnalysis(data.Analysis);
        });
        setLoading(false);
      } catch (error) {
        console.error("Error fetching Yume data:", error);
        return null;
      }
    };
    DreamSummary();
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
                {questions.map((q,index) => (
                  <QAItem
                    key={index}
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
              {dreamAnalysis && (
                <div className="my-4 p-4 bg-gray-200 rounded-lg">
                  <h2 className="text-gray-700 font-bold">
                    夢の分析と具体化：
                  </h2>
                  <p className="text-gray-600 mt-2">{dreamAnalysis}</p>
                </div>
              )}
            </div>
          </div>
        </>
      )}
    </div>
  );
}
