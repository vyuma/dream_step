import { useState } from "react";
import CheckBox from "./CheckBox";

type Task = {
  date: string;
  object: string;
  task: string[];
};

const DreamItem: React.FC<{
  task: Task;
  isOpen: boolean;
  onToggle: () => void;
}> = ({ task, isOpen, onToggle }) => {
  const [completedTasks, setCompletedTasks] = useState<boolean[]>(
    new Array(task.task.length).fill(false)
  );

  const handleCheckboxChange = (index: number) => {
    const newCompletedTasks = [...completedTasks];
    newCompletedTasks[index] = !newCompletedTasks[index];
    setCompletedTasks(newCompletedTasks);
  };

  return (
    <li className="border border-pink-200 p-6 my-4 rounded-xl shadow-lg hover:shadow-xl transition-all duration-300 bg-white backdrop-blur-sm">
      {/* ヘッダー部分（クリックで開閉） */}
      <div
        className="flex justify-between items-center cursor-pointer"
        onClick={onToggle}
      >
        <div>
          <h2 className="text-lg font-semibold text-rose-400">{task.date}</h2>
          <p className="text-gray-700 font-medium text-lg">{task.object}</p>
        </div>
        <span className="text-xl text-gray-500">{isOpen ? "▲" : "▼"}</span>
      </div>

      {/* 開閉する部分 */}
      <div
        className={`overflow-hidden transition-all duration-300 ${
          isOpen ? "max-h-96 opacity-100 mt-4" : "max-h-0 opacity-0"
        }`}
      >
        <ul className="space-y-2">
          {task.task.map((t, i) => (
            <li key={i} className="flex items-start space-x-2 text-gray-600">
              <CheckBox
                checked={completedTasks[i]}
                onChange={() => handleCheckboxChange(i)}
                label={t}
              />
              <span>{t}</span>
            </li>
          ))}
        </ul>
      </div>
    </li>
  );
};

export default DreamItem;
