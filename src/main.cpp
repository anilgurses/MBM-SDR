#include "mbm-sdr/tmp.h"
#include <iostream>
#include <stdint.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>

#ifdef __linux__
    #include <iio.h>
#elif __APPLE__
    #include <iio/iio.h>
#endif





using namespace std;

/* helper macros */
#define MHZ(x) ((long long)(x*1000000.0 + .5))
#define GHZ(x) ((long long)(x*1000000000.0 + .5))

/* common RX and TX streaming params */
struct stream_cfg {
	long long bw_hz; // Analog banwidth in Hz
	long long fs_hz; // Baseband sample rate in Hz
	long long lo_hz; // Local oscillator frequency in Hz
	const char* rfport; // Port name
};



enum iodev { RX, TX };

int main(){
    iio_scan_context *scn = iio_create_scan_context(NULL, 0);
    struct iio_context_info** lst;
    ssize_t n = iio_scan_context_get_info_list(scn, &lst);
    cout << n << endl;
}

