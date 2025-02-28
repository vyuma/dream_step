import React from "react";

type ButtonProps = {
  label: string;

  className?: string;
};

const Button: React.FC<ButtonProps> = ({ label, className }) => {
  return (
    <button
      type="submit"
      className={`px-8 py-4 bg-white text-rose-400 font-bold  rounded-full ${className}`}
      style={{ borderRadius: "9999px" }}
    >
      {label}
    </button>
  );
};

export default Button;
