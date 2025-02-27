"use client";
import { useEffect, useState } from "react";
import DreamItem from "./DreamItem";
import SakuraIcon from "./Sakura";
import SakuraLoading from "../components/SakuraLoading";

type Task = {
  date: string;
  object: string;
  task: string[];
};

export default function DreamList() {
  const [tasks, setTasks] = useState<Task[]>([]);
  const [openStates, setOpenStates] = useState<boolean[]>([]); 
  const [loading, setLoading] = useState(false);

  const fetchTasks = async (dreams:string) => {
    
  }
// utils/fetchYumeData.ts
  const fetchDreamTasks = async (summary: string) => {
    try {
      const response = await fetch(process.env.NEXT_PUBLIC_API_URL +"api/get_object_and_tasks", {
        method: "POST",
        headers: {
          "Content-Type": "application/json",
        },
        body: JSON.stringify({
            "Summary": summary
        }),
      });

      if (!response.ok) {
        throw new Error(`HTTP error! Status: ${response.status}`);
      }

      response.json().then((data: {
        tasks: { Date: string; Object: string; Task: string[] }[];
      }) => {
        const formattedTasks: Task[] = data.tasks.map((task) => ({
          date: task.Date,
          object: task.Object,
          task: task.Task,
        }));
        setTasks(formattedTasks);
        setOpenStates(formattedTasks.map((_, i) => i === 0)); // index: 0だけ開く
      });
      return response;

    } catch (error) {
      console.error("Error fetching Yume data:", error);
      return null;
    }
  };


  useEffect(() => {
    // ここは
    const dreamSummary = "フルスタックエンジニアになりたいです";
    if (!dreamSummary) {
      return alert("夢がありません");
    }
    setLoading(true);
    const yume_task= fetchDreamTasks(dreamSummary);
    setLoading(false);
  }, []);

  const handleToggle = (index: number) => {
    setOpenStates((prev) => {
      const newStates = [...prev];
      newStates[index] = !newStates[index]; // クリックした項目を開閉
      return newStates;
    });
  };

  return (
    <div className="min-h-screen">
      <div className="py-12">
        <h1 className="text-3xl font-bold text-center mb-8 text-gray-800 flex items-center justify-center">
          <span className="bg-clip-text text-transparent bg-gradient-to-r from-[#FC67B1] to-pink-400 mr-2">
            夢の細分化タスク
          </span>
          <SakuraIcon />
        </h1>
        {loading && (
          <SakuraLoading />
        )}

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
