import * as React from 'react';
import { styled } from '@mui/material/styles';
import Box from '@mui/material/Box';
import Grid from '@mui/material/Grid';
import Typography from '@mui/material/Typography';
import Slider, { SliderThumb } from '@mui/material/Slider';
import MuiInput from '@mui/material/Input';
import PropTypes from 'prop-types';
import Tooltip from '@mui/material/Tooltip';

const Input = styled(MuiInput)`
  width: 42px;
`;

export default function InputSlider() {
  const [value, setValue] = React.useState(30);

  const handleSliderChange = (event, newValue) => {
    setValue(newValue);
  };

  const handleInputChange = (event) => {
    setValue(event.target.value === '' ? 0 : Number(event.target.value));
  };

  const handleBlur = () => {
    if (value < 0) {
      setValue(0);
    } else if (value > 800) {
      setValue(800);
    }
  };

  return (
    <Box sx={{ width: 250 }}>
      <Typography id="input-slider" gutterBottom>
      Down Payment Amount
      </Typography>
      <Grid container spacing={2} alignItems="center">
        <Grid item xs>
          <Slider
            value={typeof value === 'number' ? value : 0}
            onChange={handleSliderChange}
            max={800}
            aria-labelledby="input-slider"
            color="secondary"
          />
        </Grid>
        <Grid item>
          <Input
            value={value}
            size="small"
            onChange={handleInputChange}
            onBlur={handleBlur}
            inputProps={{
              step: 2,
              min: 0,
              max: 800,
              type: 'number',
              'aria-labelledby': 'input-slider',
            }}
          />
        </Grid>
      </Grid>
    </Box>
  );
  
}

