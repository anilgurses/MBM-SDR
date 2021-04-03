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



#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H


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
#include <vector>


class deviceManager {

enum iodev { RX, TX };

public:
    deviceManager();
    bool isExist();
    ssize_t getDeviceCount();

    void getDeviceList(std::vector<std::string>& dList);

    static bool get_ad9361_stream_dev(struct iio_context *ctx, int d, struct iio_device **dev);

    static void shutdown();


private:
    ssize_t m_deviceCount;

    /* IIO structs required for streaming */
    struct iio_context *ctx;
    struct iio_channel *rx0_i;
    struct iio_channel *rx0_q;
    struct iio_channel *tx0_i;
    struct iio_channel *tx0_q;
    struct iio_buffer  *rxbuf;
    struct iio_buffer  *txbuf;
    struct iio_context_info** lst;
};


#endif