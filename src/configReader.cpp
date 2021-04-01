#include "mbm-sdr/configReader.h"


bool configReader::readConfig(std::string cfgPath) {
    std::ifstream cfgFile;
    cfgFile.open(cfgPath);

    std::stringstream confStream;
    confStream << cfgFile.rdbuf(); 
    std::string config = confStream.str(); 

    char* cfgChar;
    cfgChar = &config[0];


    if (m_document.Parse(cfgChar).HasParseError())
        return false;
    else
        return true;
}

std::string configReader::getConfigForKey(std::string key) {
    char* cfgKey;
    cfgKey = &key[0];
    return m_document[cfgKey].GetString();
}