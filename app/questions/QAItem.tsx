import React from "react";

type Question = { id: number; text: string };

interface QAItemProps {
  question: Question;
  answer: string;
  onChange: (id: number, value: string) => void;
}

const QAItem: React.FC<QAItemProps> = ({ question, answer, onChange }) => {
  return (
    <div className="space-y-2 p-4">
      <div className="flex items-center space-x-2">
        <div className="w-10 h-10 flex items-center justify-center bg-rose-400 text-white font-bold">
          Q
        </div>
        <p className="text-gray-700 font-semibold">{question.text}</p>
      </div>
      <div className="flex items-center space-x-2 mt-2">
        <div className="w-10 h-10 flex items-center justify-center bg-black text-white font-bold">
          A
        </div>
        <textarea
          className="w-full p-2 bg-white border border-gray-300 text-black"
          placeholder={answer}
          onChange={(e) => onChange(question.id, e.target.value)}
          rows={3}
        />
      </div>
    </div>
  );
};

export default QAItem;
