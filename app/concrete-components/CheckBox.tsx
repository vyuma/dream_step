import React from "react";

type CheckboxProps = {
  checked: boolean;
  onChange: () => void;
  label?: string;
};

const Checkbox: React.FC<CheckboxProps> = ({ checked, onChange}) => {
  return (
    <label className="flex items-center space-x-2 cursor-pointer">
      <input
        type="checkbox"
        checked={checked}
        onChange={onChange}
        className="w-5 h-5 accent-pink-500"
      />
    </label>
  );
};

export default Checkbox;
