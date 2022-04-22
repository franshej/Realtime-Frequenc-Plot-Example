# Realtime frequency plot example app

![Image](img/ui.png)

This is a simple example app for the CustomMatPlot Library. It plots the frequency response of the incoming microphone signal or the chosen input in the device manager. The app is based on the SimpleFFT example from JUCE.

## Requirements
<a name="requirements"></a>

- Compiler that supports C++17
- CMake 3.12

## Build
```sh
# Clone respiratory
git clone https://gitlab.com/frans.rosencrantz/realtime-frequency-plot-example.git
cd realtime-frequency-plot-example

mkdir build
cd build
# Configure
cmake ../

# Build
make -j4
```

## License
<a name="license"></a>

The MIT License (MIT)

Copyright (c) 2017-2022 Frans Rosencrantz

**Free Software, Hell Yeah!**