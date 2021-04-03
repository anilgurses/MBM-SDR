/* 
*    The MIT License (MIT)
*
*    Copyright (c) 2019 Anil Gurses
*
*    Permission is hereby granted, free of charge, to any person obtaining a copy of
*    this software and associated documentation files (the "Software"), to deal in
*    the Software without restriction, including without limitation the rights to
*    use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
*    the Software, and to permit persons to whom the Software is furnished to do so,
*    subject to the following conditions:
*
*    The above copyright notice and this permission notice shall be included in all
*    copies or substantial portions of the Software.
*
*    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
*    FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
*    COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
*    IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
*    CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <iostream>
#include <stdint.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include "mbm-sdr/deviceManager.h"
#include "spdlog/spdlog.h"


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

#define IIO_ENSURE(expr) { \
	if (!(expr)) { \
		(void) spdlog::error( "assertion failed ({}:{})\n", __FILE__, __LINE__); \
		(void) abort(); \
	} \
}

deviceManager::deviceManager() {
    m_deviceCount = 0;
}

bool deviceManager::isExist() {
    iio_scan_context *scn = iio_create_scan_context(NULL, 0);
    m_deviceCount = iio_scan_context_get_info_list(scn, &lst);
    if(m_deviceCount > 0 ){
        return true;
    }else{
        return false;
    }
}

void deviceManager::getDeviceList(std::vector<std::string>& dList) {

    dList.clear();
    iio_scan_context *scn = iio_create_scan_context(NULL, 0);
    iio_scan_context_get_info_list(scn, &lst);

    for(ssize_t i = 0; i < m_deviceCount; i++) {
        dList.push_back(iio_context_info_get_uri(lst[i]));
    }

}

ssize_t deviceManager::getDeviceCount() {
    return m_deviceCount;
}

/* finds AD9361 streaming IIO devices */
bool deviceManager::get_ad9361_stream_dev(struct iio_context *ctx, int d, struct iio_device **dev)
{
	switch (d) {
	case 0: *dev = iio_context_find_device(ctx, "cf-ad9361-dds-core-lpc"); return *dev != NULL;
	case 1: *dev = iio_context_find_device(ctx, "cf-ad9361-lpc");  return *dev != NULL;
	default: return false;
	}
}


void deviceManager::shutdown()
{
	spdlog::info("* Destroying buffers");
	// if (rxbuf) { iio_buffer_destroy(rxbuf); }
	// if (txbuf) { iio_buffer_destroy(txbuf); }

	// spdlog::info("* Disabling streaming channels");
	// if (rx0_i) { iio_channel_disable(rx0_i); }
	// if (rx0_q) { iio_channel_disable(rx0_q); }
	// if (tx0_i) { iio_channel_disable(tx0_i); }
	// if (tx0_q) { iio_channel_disable(tx0_q); }

	// spdlog::info("* Destroying context");
	// if (ctx) { iio_context_destroy(ctx); }
}




