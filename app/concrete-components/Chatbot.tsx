"use client";

import Button from "../components/Button";

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

          <div className="mt-2">
            <textarea
              id="question"
              rows={5}
              value={prompt}
              onChange={(e) => setPrompt(e.target.value)}
              placeholder="質問を入力してください..."
              className="w-full px-4 py-3 rounded-lg border-2 border-white bg-transparent text-white placeholder-white focus:outline-none focus:ring-2 focus:ring-white"
            />
          </div>
        </div>
        <div className="flex justify-end">
          <button
            className="px-8 py-4  bg-white text-rose-400 font-bold  rounded-full"
            onClick={generateAnswer}

            disabled={prompt.length === 0}
            type="submit"
          >
            質問する
          </button>
        </form>
        {answer && (
          <>
            <div className="font-medium leading-6 text-lg text-white pb-2">
              回答：
            </div>
            <p className="mt-2 text-white">{answer}</p>
          </>
        )}
      </div>
    </>
  );
};

export default Chatbot;
