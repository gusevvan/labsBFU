#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>

namespace utils {
    short messageLevel = 3;

    enum class LogLevel {
        INFO,
        DEBUG,
        ERROR
    };

    class Logger {
        std::stringstream _outLog;
        std::ofstream _FOut;
        LogLevel _level;
    public:
        explicit Logger(LogLevel level, const std::string& path) : _level(level) {
            _FOut.open(path, std::ofstream::app);
        }
        template<typename T>
        Logger& operator<<(const T& t)
        {
             _outLog << t;
            return *this;
        }
        ~Logger()
        {
            const time_t timer = time(NULL);
            switch (_level) {
                case LogLevel::ERROR: {
                    if (messageLevel >= 1) {
                        _FOut << "*\n[ERROR]\n" << ctime(&timer) << _outLog.str() << "\n*\n";
                        std::cerr << "*\n[ERROR]\n" << ctime(&timer) << _outLog.str() << "\n*\n";
                        _FOut.flush();
                    }
                    break;
                }
                case LogLevel::DEBUG: {
                    if (messageLevel >= 2) {
                        _FOut << "*\n[DEBUG]\n" << ctime(&timer) << _outLog.str() << "\n*\n";
                        std::cerr << "*\n[DEBUG]\n" << ctime(&timer) << _outLog.str() << "\n*\n";
                        _FOut.flush();
                    }
                    break;
                }
                case LogLevel::INFO: {
                    if (messageLevel >= 3) {
                        _FOut << "*\n[INFO]\n" << ctime(&timer) << _outLog.str() << "\n*\n";
                        std::cerr << "*\n[INFO]\n" << ctime(&timer) << _outLog.str() << "\n*\n";
                        _FOut.flush();
                    }
                    break;
                }
            }
        }
    };
}

