#ifndef LOG_HPP
#define LOG_HPP
#include <string_view>
using namespace std;

static constexpr string_view S_RED = "\033[31m";
static constexpr string_view S_BOLD_RED = "\033[1;31m";
static constexpr string_view S_GREEN = "\033[32m";
static constexpr string_view S_YELLOW = "\033[33m";
static constexpr string_view RESET = "\033[0m";

namespace LOG {
    enum LEVEL{
        ERROR,
        HIGH,
        MEDIUM,
        LOW,
    };
    string_view level_to_str(LEVEL l);
    struct PRINT{
        const char *messages;
        LEVEL warning;

        PRINT(const char *m, LEVEL w);
    };
}
#endif//LOG_HPP
