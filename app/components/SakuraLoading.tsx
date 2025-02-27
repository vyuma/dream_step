"use client";
import React from "react";
import "./Sakura.css";

const SakuraLoading: React.FC = () => {
  const petalCount = 20; // 花びらの数
  const petalImages = [
    "https://adatype.co.jp/info/wp-content/uploads/2021/03/parts_01.png",
    "https://adatype.co.jp/info/wp-content/uploads/2021/03/parts_02.png",
    "https://adatype.co.jp/info/wp-content/uploads/2021/03/parts_03.png",
    "https://adatype.co.jp/info/wp-content/uploads/2021/03/parts_04.png",
    "https://adatype.co.jp/info/wp-content/uploads/2021/03/parts_05.png",
    "https://adatype.co.jp/info/wp-content/uploads/2021/03/parts_06.png",
    "https://adatype.co.jp/info/wp-content/uploads/2021/03/parts_07.png",
    "https://adatype.co.jp/info/wp-content/uploads/2021/03/parts_01.png",
    "https://adatype.co.jp/info/wp-content/uploads/2021/03/parts_02.png",
    "https://adatype.co.jp/info/wp-content/uploads/2021/03/parts_03.png",
    "https://adatype.co.jp/info/wp-content/uploads/2021/03/parts_04.png",
    "https://adatype.co.jp/info/wp-content/uploads/2021/03/parts_05.png",
    "https://adatype.co.jp/info/wp-content/uploads/2021/03/parts_06.png",
    "https://adatype.co.jp/info/wp-content/uploads/2021/03/parts_07.png",
    "https://adatype.co.jp/info/wp-content/uploads/2021/03/parts_01.png",
    "https://adatype.co.jp/info/wp-content/uploads/2021/03/parts_02.png",
    "https://adatype.co.jp/info/wp-content/uploads/2021/03/parts_03.png",
    "https://adatype.co.jp/info/wp-content/uploads/2021/03/parts_04.png",
    "https://adatype.co.jp/info/wp-content/uploads/2021/03/parts_05.png",
    "https://adatype.co.jp/info/wp-content/uploads/2021/03/parts_06.png",

  ];

  return (
    <div id="sakura_block">
      <div className="sakura_parts_box">
        {Array.from({ length: petalCount }).map((_, i) => {
          const leftPosition = Math.random() * 100; // 0% ～ 100% の間でランダム
          const delay = Math.random() * 5; // 0s ～ 5s の間でランダム
          const image = petalImages[i % petalImages.length]; // 花びら画像を順番に使用

          return (
            <img
              key={i}
              src={image}
              alt=""
              className={`parts_${i + 1}`}
              
            />
          );
        })}
      </div>
    </div>
  );
};

export default SakuraLoading;
