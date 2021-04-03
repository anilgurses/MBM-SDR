set(sources
    src/tmp.cpp
    src/configReader.cpp
)

file(GLOB uiFiles
     "src/uiSource/*.ui"
)

file(GLOB uiSource 
    "src/ui/*.cpp"
    "include/ui/*.h"
)

file(GLOB plutoSource 
    "src/Pluto/*.cpp"
)

set(exe_sources
    src/main.cpp
    ${plutoSource}
    ${uiFiles}
    ${uiSource}
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
