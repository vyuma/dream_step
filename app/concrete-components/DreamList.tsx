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

  useEffect(() => {
    fetch("/tasks.json")
      .then((res) => res.json())
      .then((data) => setTasks(data.tasks));
  }, []);

  console.log(tasks);

  return (
    <div className="min-h-screen bg-gradient-to-br from-pink-50 via-white to-pink-100">
      <div className="max-w-3xl mx-auto px-4 py-12">
        <h1 className="text-3xl font-bold text-center mb-8 text-gray-800">
          <span className="bg-clip-text text-transparent bg-gradient-to-r from-[#FC67B1] to-pink-400">
            夢の細分化タスク
          </span>
          <span className="text-base ml-2 text-gray-500">（仮）</span>
        </h1>
        <ul className="space-y-6">
          {tasks.map((task, index) => (
            <DreamItem key={index} task={task} />
          ))}
        </ul>
      </div>
    </div>
  );
}
