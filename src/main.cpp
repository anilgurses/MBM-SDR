#include <iostream>
#include <stdint.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>


#include "mbm-sdr/tmp.h"
#include "mbm-sdr/deviceManager.h"
#include "mbm-sdr/configReader.h"
#include "mbm-sdr/definitions.h"
#include "spdlog/spdlog.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
   #ifdef _WIN64
      //Windows (64-bit only)
   #else
      //Windows (32-bit only)
   #endif
#elif __linux__
    #include <iio.h>
#elif __APPLE__
    #include <iio/iio.h>
#endif


/* IIO structs required for streaming */
static struct iio_context *ctx   = NULL;
static struct iio_channel *rx0_i = NULL;
static struct iio_channel *rx0_q = NULL;
static struct iio_channel *tx0_i = NULL;
static struct iio_channel *tx0_q = NULL;
static struct iio_buffer  *rxbuf = NULL;
static struct iio_buffer  *txbuf = NULL;

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


void txStart(deviceManager dMng) {

}

void rxStart(deviceManager dMng) {


}

int main(){
    deviceManager dManager;
    configReader cReader;

    std::string cfgPatg = "config.json";
    
    if(cReader.readConfig(cfgPatg)) {
        spdlog::info("Config found on path: {}", cfgPatg);
    }else {
        spdlog::error("Config is not found. Exiting...");
    }

    std::string deviceType = cReader.getConfigForKey(KEY_TYPE);
    
    spdlog::info("Device Type: {}", deviceType);

    auto isDeviceExist = dManager.isExist();

    if(isDeviceExist){
        spdlog::info("Device Found. Count : {}", dManager.getDeviceCount());
    }else{
        spdlog::error("Device Not Found. Exiting...");
        return 0;
    }

    spdlog::info("Software Init Completed. Starting ");

    if(deviceType == "tx") {
        txStart(dManager);
    }else if(deviceType == "rx") {
        rxStart(dManager);
    }else {
        spdlog::error("Device type configuration wrong. It must be tx or rx");
    }


}



/* cleanup and exit */
static void shutdown()
{
	printf("* Destroying buffers\n");
	if (rxbuf) { iio_buffer_destroy(rxbuf); }
	if (txbuf) { iio_buffer_destroy(txbuf); }

	printf("* Disabling streaming channels\n");
	if (rx0_i) { iio_channel_disable(rx0_i); }
	if (rx0_q) { iio_channel_disable(rx0_q); }
	if (tx0_i) { iio_channel_disable(tx0_i); }
	if (tx0_q) { iio_channel_disable(tx0_q); }

	printf("* Destroying context\n");
	if (ctx) { iio_context_destroy(ctx); }
	exit(0);
}




