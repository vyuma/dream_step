"use client";
import React, { FormEvent, useState } from "react";

const Chatbot = () => {
  const [prompt, setPrompt] = useState<string>("");
  const [answer, setAnswer] = useState<string>("");
  const [isLoading, setIsLoading] = useState<boolean>(false);

  const onSubmit = async (event: FormEvent) => {
    event.preventDefault();

    // 質問を再度投げた際に前回の回答をリセット
    setAnswer("");
    setIsLoading(true);

    const response = await fetch('/api/ai', {
      method: "POST",
      body: JSON.stringify({prompt})
    });
    const reader = response.body?.pipeThrough(new TextDecoderStream()).getReader();



    if (!response.ok) {
      throw new Error(`サーバーエラー: ${response.status}`);
    }

    if (reader === undefined) {
      return;
    }
    
    while(true) {
      const readResponse = await reader.read();
      if (readResponse.done) {
        break;
      }

      setAnswer((prev) => prev + readResponse.value)
    }

    setIsLoading(false);
  }

  return (
    <div className="px-4 py-6 max-w-4xl mx-auto">
      {/* 質問エリア */}
      <div className="mb-6">
        <label
          htmlFor="question"
          className="block font-medium leading-6 text-lg text-gray-900 pb-2"
        >
          質問：
        </label>
        <div className="mt-2">
          <textarea
            id="question"
            className="block w-full rounded-md border-0 py-1.5 px-2 text-gray-900 shadow-sm ring-1 ring-inset ring-gray-300 placeholder:text-gray-400 focus:ring-2 focus:ring-inset focus:ring-indigo-600 sm:text-sm sm:leading-6"
            placeholder="質問を入力してください"
            maxLength={500}
            rows={5}
            value={prompt}
            onChange={(e) => setPrompt(e.target.value)}
          />
        </div>
        <div className="flex justify-end mt-4">
          <button
            onClick={onSubmit}
            className="rounded-md bg-indigo-600 px-6 py-2.5 text-sm font-semibold text-white shadow-sm hover:bg-indigo-500 focus-visible:outline focus-visible:outline-2 focus-visible:outline-offset-2 focus-visible:outline-indigo-600"
            disabled={prompt.length === 0 || isLoading}
            type="button"
          >
            {isLoading ? "読み込み中..." : "質問する"}
          </button>
        </div>
      </div>

      {/* 回答エリア - 画面右に30%幅の固定領域 */}
      <div className="relative">
        <div className="font-medium leading-6 text-lg text-gray-900 pb-2">
          回答：
        </div>
        <pre className="w-full rounded-md p-4 min-h-32 border border-gray-200 bg-gray-50 whitespace-pre-wrap text-gray-700 overflow-y-auto">
          {answer || "回答がここに表示されます"}
        </pre>
      </div>
    </div>
  );
};


export default Chatbot;
