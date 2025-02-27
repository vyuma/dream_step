"use client";
import { useEffect, useState } from "react";
import DreamItem from "./DreamItem";


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
    <div className="min-h-screen ml-20">
      <div className="py-12">
        <h1 className="text-3xl font-bold text-center mb-8 text-gray-800 flex items-center justify-center">
          <span className="text-white mr-2 text-4xl tracking-[5px]">
            - ゆめステップ -
          </span>
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
