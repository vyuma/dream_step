type Task = {
  date: string;
  object: string;
  task: string[];
};

const DreamItem: React.FC<{ task: Task }> = ({ task }) => {
  return (
    <li className="border border-pink-200 p-6 my-4 rounded-xl shadow-lg hover:shadow-xl transition-all duration-300 bg-white/80 backdrop-blur-sm">
      <h2 className="text-lg font-semibold text-[#FC67B1] mb-3">{task.date}</h2>
      <p className="text-gray-700 font-medium mb-4 text-lg">{task.object}</p>
      <ul className="space-y-2">
        {task.task.map((t, i) => (
          <li key={i} className="flex items-start space-x-2 text-gray-600">
            <span className="text-[#FC67B1] mt-1">•</span>
            <span>{t}</span>
          </li>
        ))}
      </ul>
    </li>
  );
};

export default DreamItem;
