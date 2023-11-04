import './App.css'
import React, { useState } from 'react';

const Slider = () => {
  const [value, setValue] = useState(400);

  const handleChange = (e) => {
    setValue(e.target.value);
  };

  return (
    <div className="slider-container">
      <input
        type="range"
        min="0"
        max="800"
        step="1"
        value={value}
        onChange={handleChange}
        className="slider"
      />
      <input
        type="number"
        min="0"
        max="800"
        step="1"
        value={value}
        onChange={handleChange}
        className="value-input"
      />
    </div>
  );
};

export default Slider;
