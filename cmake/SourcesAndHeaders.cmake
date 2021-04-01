set(sources
    src/tmp.cpp
    src/configReader.cpp
)

set(exe_sources
    src/main.cpp
    src/Pluto/deviceManager.cpp
    ${sources}
)

file(GLOB headerFiles
     "include/mbm-sdr/*.h"
     "include/rapidjson/*.h"
     "include/spdlog/*.h"
)

set(headers
    ${headerFiles}
)
