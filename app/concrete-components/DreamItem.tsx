import { useState } from "react";

type Task = {
  date: string;
  object: string;
  task: string[];
};

const DreamItem: React.FC<{ task: Task }> = ({ task }) => {
  const [isOpen, setIsOpen] = useState(false);
  const [completedTasks, setCompletedTasks] = useState<boolean[]>(
    new Array(task.task.length).fill(false)
  );

  const handleCheckboxChange = (index: number) => {
    const newCompletedTasks = [...completedTasks];
    newCompletedTasks[index] = !newCompletedTasks[index];
    setCompletedTasks(newCompletedTasks);
  };

  const handleToggle = () => {
    setIsOpen(!isOpen);
  };

  return (
    <li className="border border-pink-200 p-6 my-4 rounded-xl shadow-lg hover:shadow-xl transition-all duration-300 bg-white/80 backdrop-blur-sm">
      {/* dateとobjectだけ表示（クリックで開閉） */}
      <div
        className="flex justify-between items-center cursor-pointer"
        onClick={handleToggle}
      >
        <div>
          <h2 className="text-lg font-semibold text-[#FC67B1]">{task.date}</h2>
          <p className="text-gray-700 font-medium text-lg">{task.object}</p>
        </div>
        <span className="text-xl text-gray-500">{isOpen ? "▲" : "▼"}</span>
      </div>

      <div
        className={`overflow-hidden transition-all duration-300 ${
          isOpen ? "max-h-96 opacity-100 mt-4" : "max-h-0 opacity-0"
        }`}
      >
        <ul className="space-y-2">
          {task.task.map((t, i) => (
            <li key={i} className="flex items-start space-x-2 text-gray-600">
              <input
                type="checkbox"
                checked={completedTasks[i]}
                onChange={() => handleCheckboxChange(i)}
                className="w-5 h-5"
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
