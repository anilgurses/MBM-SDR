[![Actions Status](https://github.com/anilgurses/MBM-SDR/workflows/MacOS/badge.svg)](https://github.com/anilgurses/MBM-SDR/actions)
[![Actions Status](https://github.com/anilgurses/MBM-SDR/workflows/Windows/badge.svg)](https://github.com/anilgurses/MBM-SDR/actions)
[![Actions Status](https://github.com/anilgurses/MBM-SDR/workflows/Ubuntu/badge.svg)](https://github.com/anilgurses/MBM-SDR/actions)
[![codecov](https://codecov.io/gh/anilgurses/MBM-SDR/branch/master/graph/badge.svg)](https://codecov.io/gh/anilgurses/MBM-SDR)
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/anilgurses/MBM-SDR)](https://github.com/anilgurses/MBM-SDR/releases)

## Building MBM-SDR
For building this project you need **CMAKE > 3.15**. Currently this project supports Linux and Mac OS X systems. 

```
$ mkdir build && cd build
$ cmake .. 
$ make -j$(nproc)
$ sudo make install 
```
