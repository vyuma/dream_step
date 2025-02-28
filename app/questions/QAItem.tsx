
export type Question = {
  Question: string;
  Answer: string;
};
type AnswerTextProps = {
  question: Question;
  index: number;
  handleAnswerChange: (index: number, value: string) => void;
};


export default function AnswerText({ question, index, handleAnswerChange }: AnswerTextProps) {
  return ( 
    <div className="space-y-2 p-4">
    <div className="flex items-center space-x-2">
      <div className="w-10 h-10 flex items-center justify-center bg-rose-400 text-white font-bold">
        Q
      </div>
      <p className="text-gray-700 font-semibold">{question.Question}</p>
    </div>
    <div className="flex items-center space-x-2 mt-2">
      <div className="w-10 h-10 flex items-center justify-center bg-black text-white font-bold">
        A
      </div>
      <textarea
        className="w-full p-2 bg-white border border-gray-300 text-black"
        placeholder={question.Answer}
        onChange={(e) => handleAnswerChange(index, e.target.value)}
        rows={3}
      />
    </div>
  </div>
  )

}

