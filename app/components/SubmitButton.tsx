import React from "react";

type ButtonProps = {
  label: string;
  className?: string;
  isLoading?: boolean;
};

const Button: React.FC<ButtonProps> = ({ label, className, isLoading = false }) => {
  return (
    <button
      type="submit"
      disabled={isLoading}
      className={`px-8 py-4 font-bold rounded-full ${
        isLoading 
          ? 'bg-gray-300 text-gray-500 cursor-not-allowed' 
          : 'bg-white text-rose-400 hover:bg-rose-50'
      } ${className}`}
      style={{ borderRadius: "9999px" }}
    >
      <div className="flex items-center justify-center">
        {isLoading && (
          <svg className="animate-spin -ml-1 mr-3 h-5 w-5 text-rose-400" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24">
            <circle className="opacity-25" cx="12" cy="12" r="10" stroke="currentColor" strokeWidth="4"></circle>
            <path className="opacity-75" fill="currentColor" d="M4 12a8 8 0 018-8V0C5.373 0 0 5.373 0 12h4zm2 5.291A7.962 7.962 0 014 12H0c0 3.042 1.135 5.824 3 7.938l3-2.647z"></path>
          </svg>
        )}
        {label}
      </div>
    </button>
  );
};

export default Button;