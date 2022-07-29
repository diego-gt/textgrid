#pragma once

#include "Visibility.hpp"
#include <string>

// TODO: support text styles
// enum USC_DLL_EXPORT CharacterVariant { Regular,
//     Bold,
//     Dotted };

namespace text {
struct USC_DLL_EXPORT DisplayCharacter {
    std::string ascii;
    std::string unicode;
};

struct USC_DLL_EXPORT DisplayCorner {
    DisplayCharacter upper_left;
    DisplayCharacter upper_right;
    DisplayCharacter lower_left;
    DisplayCharacter lower_right;
};

struct USC_DLL_EXPORT DisplayBorder {
    DisplayCharacter horizontal;
    DisplayCharacter vertical;
};

enum USC_DLL_EXPORT Alignment {
    Center,
    Left,
    Right,
    Top,
    Bottom,
    Middle
};

const DisplayCorner corners {
    .upper_left { .ascii = "+", .unicode = "┌" },
    .upper_right { .ascii = "+", .unicode = "┐" },
    .lower_left { .ascii = "+", .unicode = "└" },
    .lower_right { .ascii = "+", .unicode = "┘" }
};

const DisplayBorder borders {
    .horizontal { .ascii = "-", .unicode = "─" },
    .vertical { .ascii = "|", .unicode = "│" }
};
}
