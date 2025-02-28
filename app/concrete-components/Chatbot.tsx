"use client";
import React, { FormEvent, useState } from "react";
import { continueConversation } from "../actions";

const Chatbot = () => {
  const [prompt, setPrompt] = useState<string>("");
  const [answer, setAnswer] = useState<string>("");

  const onSubmit = async (event: FormEvent) => {
    event.preventDefault();

    const response = await fetch('/api/ai', {
      method: "POST",
      body: JSON.stringify({prompt})
    });
    const reader = response.body?.pipeThrough(new TextDecoderStream()).getReader();

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
  }

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
        <form className="flex justify-end mb-8" onSubmit={onSubmit}>
          <button
            className="rounded-md bg-indigo-600 px-6 py-2.5 text-sm font-semibold text-white shadow-sm hover:bg-indigo-500 focus-visible:outline focus-visible:outline-2 focus-visible:outline-offset-2 focus-visible:outline-indigo-600"
            disabled={prompt.length === 0}
            type="submit"
          >
            質問する
          </button>
        </form>
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
