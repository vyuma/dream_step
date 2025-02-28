"use client";

import { useState } from "react";
import { useRouter } from "next/navigation";
import Button from "./components/SubmitButton";

export default function Home() {
  const [dream, setDream] = useState("");
  const [loading, setLoading] = useState(false);
  const router = useRouter();

  const handleSubmit = async (e: React.FormEvent) => {
    e.preventDefault();
    console.log("handleSubmit");
    if (!dream.trim()) return;
    try {
      setLoading(true);
      const res = await fetch("http://localhost:8000/api/yume_question", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({ Prompt: dream }),
      });

      console.log("Response status:", res.status);

      if (res.ok) {
        const data = await res.json();
        console.log("API Response:", data);

        // ここでデータをセットせず、questionsページで取得するようにする

        // セッションストレージに夢を保存
        sessionStorage.setItem("dream", dream);

        if (data && data.Question) {
          sessionStorage.setItem("questionData", JSON.stringify(data));
        }

        router.push("/questions");
      } else {
        const errorData = await res.text();
        console.error("API Error:", errorData);
        alert("エラーが発生しました");
        setLoading(false);
      }
    } catch (error) {
      console.error("Fetch Error:", error);
      alert("通信エラーが発生しました");
      setLoading(false);
    }
  };

  return (
    <div className="min-h-screen bg-rose-400 flex items-center justify-center">
      <div className="container mx-auto px-4 py-12 md:py-24">
        <div className="flex flex-col md:flex-row items-center justify-between gap-12">
          <div className="w-full md:w-1/2 space-y-8 text-white">
            <h1 className="text-[80px] font-bold leading-tight">Dream Step</h1>
            <p className="text-xl md:text-2xl font-medium">
              AIと共に、
              <br />
              夢への道筋を明確に。
            </p>

            <div className="space-y-4 max-w-md">
              <form onSubmit={handleSubmit}>
                <textarea
                  id="dream"
                  rows={5}
                  value={dream}
                  onChange={(e) => setDream(e.target.value)}
                  placeholder="あなたの夢を入力してください..."
                  className="w-full px-4 py-3 rounded-lg border-2 border-white bg-transparent text-white placeholder-white focus:outline-none focus:ring-2 focus:ring-white"
                />
                <div className="my-10">
                  <Button label="今すぐ試してみる" />
                </div>
              </form>
            </div>
          </div>

          <div className="w-full md:w-1/2 flex justify-center">
            <div className="relative">
              <img
                src="" // 画像URLをここに追加
                alt="Laptop with code"
                className="rounded-lg shadow-2xl max-w-full h-auto"
              />
            </div>
          </div>
        </div>
      </div>
    </div>
  );
}
