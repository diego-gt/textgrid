#include "Utilities.hpp"

namespace text {
std::string RepeatString(u8 count, const std::string& str) {
    std::string result;

    for (u8 i = 0; i < count; i++) {
        result += str;
    }

    return result;
}
}
