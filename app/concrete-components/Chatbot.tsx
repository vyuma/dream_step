"use client";
import React, { useState } from "react";

const Chatbot = () => {
  const [prompt, setPrompt] = useState<string>("");
  const [answer, setAnswer] = useState<string | null>(null);

  //仮のresponse
  const responses: { [key: string]: string } = {
    こんにちは: "こんにちは！どうぞご質問ください。",
  };

  const generateAnswer = () => {
    setAnswer(
      responses[prompt] || "すみません、その質問にはまだ対応していません。"
    );
  };

  return (
    <>
      <div className="px-4">
        <div className="py-8">
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
        </div>
        <div className="flex justify-end mb-8">
          <button
            className="rounded-md bg-indigo-600 px-6 py-2.5 text-sm font-semibold text-white shadow-sm hover:bg-indigo-500 focus-visible:outline focus-visible:outline-2 focus-visible:outline-offset-2 focus-visible:outline-indigo-600"
            onClick={generateAnswer}
            disabled={prompt.length === 0}
          >
            質問する
          </button>
        </div>
        {answer && (
          <>
            <div className="font-medium leading-6 text-lg text-gray-900 pb-2">
              回答：
            </div>
            <p className="mt-2 text-gray-700">{answer}</p>
          </>
        )}
      </div>
    </>
  );
};

export default Chatbot;
