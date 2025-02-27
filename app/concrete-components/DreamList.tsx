"use client";
import { useEffect, useState } from "react";
import DreamItem from "./DreamItem";
import SakuraIcon from "./Sakura";

type Task = {
  date: string;
  object: string;
  task: string[];
};

export default function DreamList() {
  const [tasks, setTasks] = useState<Task[]>([]);
  const [openStates, setOpenStates] = useState<boolean[]>([]); 

  const fetchTasks = async (dreams:string) => {
    
  }


  useEffect(() => {
    fetch("/tasks.json")
      .then((res) => res.json())
      .then(
        (data: {
          tasks: { Date: string; Object: string; Task: string[] }[];
        }) => {
          const formattedTasks: Task[] = data.tasks.map((task) => ({
            date: task.Date,
            object: task.Object,
            task: task.Task,
          }));
          setTasks(formattedTasks);
          setOpenStates(formattedTasks.map((_, i) => i === 0)); // index: 0だけ開く
        }
      );
  }, []);

  const handleToggle = (index: number) => {
    setOpenStates((prev) => {
      const newStates = [...prev];
      newStates[index] = !newStates[index]; // クリックした項目を開閉
      return newStates;
    });
  };

  return (
    <div className="min-h-screen bg-gradient-to-br from-pink-50 via-white to-pink-100">
      <div className="max-w-3xl mx-auto px-4 py-12">
        <h1 className="text-3xl font-bold text-center mb-8 text-gray-800 flex items-center justify-center">
          <span className="bg-clip-text text-transparent bg-gradient-to-r from-[#FC67B1] to-pink-400 mr-2">
            夢の細分化タスク
          </span>
          <SakuraIcon />
        </h1>
        <ul className="space-y-6">
          {tasks.map((task, index) => (
            <DreamItem
              key={index}
              task={task}
              isOpen={openStates[index]} // 開いているかどうかを渡す
              onToggle={() => handleToggle(index)}
            />
          ))}
        </ul>
      </div>
    </div>
  );
}
