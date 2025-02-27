
export type Question = {
    Question: string;
    Anser: string;
  };
type AnswerTextProps = {
    question: Question;
    index: number;
    handleAnswerChange: (index: number, value: string) => void;
};


export default function AnswerText({ question, index, handleAnswerChange }: AnswerTextProps) {
    return ( 
        <div key={index} className="flex flex-col bg-purple-800 bg-opacity-20 border border-purple-400 border-opacity-20 p-4 rounded-lg">
                          <p className="text-white mb-2">{question.Question}</p>
                          <textarea
                            className="w-full p-2 rounded-md bg-purple-900 bg-opacity-50 text-white border border-purple-300 focus:outline-none focus:ring-2 focus:ring-pink-400 placeholder-purple-300 placeholder-opacity-30 focus:border-transparent"
                            onChange={(e) => handleAnswerChange(index, e.target.value)}
                            placeholder={question.Anser}
                            rows={3}
                          />
                        </div>
    )
}