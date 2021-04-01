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

using namespace std;

deviceManager::deviceManager() {
    m_deviceCount = 0;
}

bool deviceManager::isExist() {
    iio_scan_context *scn = iio_create_scan_context(NULL, 0);
    struct iio_context_info** lst;
    m_deviceCount = iio_scan_context_get_info_list(scn, &lst);
    if(m_deviceCount > 0 ){
        return true;
    }else{
        return false;
    }
}

ssize_t deviceManager::getDeviceCount() {
    return m_deviceCount;
}


