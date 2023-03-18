#include <iostream>
#include "Logger.hpp"
#include <time.h>

utils::Logger logInfo(const std::string& path)
{
    return utils::Logger(utils::LogLevel::INFO, path);
}

utils::Logger logDebug(const std::string& path)
{
    return utils::Logger(utils::LogLevel::DEBUG, path);
}

utils::Logger logError(const std::string& path)
{
    return utils::Logger(utils::LogLevel::ERROR, path);
}

int main() {
    utils::messageLevel = 2;
    logDebug("log.txt") << "abas";
    logInfo("log.txt") << "ba";
    utils::messageLevel = 3;
    logInfo("log.txt") << "ba";
    return 0;
}
