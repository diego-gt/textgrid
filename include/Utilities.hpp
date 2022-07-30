#pragma once

#include "Types.hpp"
#include "Visibility.hpp"

#include <string>

namespace text {

std::string RepeatString(u8 count, const std::string& str);

enum HorizontalAlignment {
    Center,
    Left,
    Right
};

enum VerticalAlignment {
    Top,
    Bottom,
    Middle
};

enum CharacterMode {
    Unicode,
    Ascii
};

class Border {
public:
    Border(CharacterMode mode)
        : m_mode(mode)
    {
    }
    ~Border() = default;

    std::string Horizontal()
    {
        switch (m_mode) {
        case Unicode:
            return "─";
        case Ascii:
            return "-";
        }
    }

    std::string Vertical()
    {
        switch (m_mode) {
        case Unicode:
            return "│";
        case Ascii:
            return "|";
        }
    }

private:
    CharacterMode m_mode = text::Unicode;
};

class Corner {
public:
    Corner(CharacterMode mode)
        : m_mode(mode)
    {
    }
    ~Corner() = default;

    std::string UpperLeft()
    {
        switch (m_mode) {
        case Unicode:
            return "┌";
        case Ascii:
            return "+";
        }
    }

    std::string UpperRight()
    {
        switch (m_mode) {
        case Unicode:
            return "┐";
        case Ascii:
            return "+";
        }
    }

    std::string LowerLeft()
    {
        switch (m_mode) {
        case Unicode:
            return "└";
        case Ascii:
            return "+";
        }
    }

    std::string LowerRight()
    {
        switch (m_mode) {
        case Unicode:
            return "┘";
        case Ascii:
            return "+";
        }
    }

private:
    CharacterMode m_mode;
};

class ConnectedCorner {
public:
    ConnectedCorner(CharacterMode mode)
        : m_mode(mode)
    {
    }
    ~ConnectedCorner() = default;

    std::string UpperLeftVertical()
    {
        switch (m_mode) {
        case Unicode:
            return "├";
        case Ascii:
            return "+";
        }
    }

    std::string UpperRightVertical()
    {
        switch (m_mode) {
        case Unicode:
            return "┤";
        case Ascii:
            return "+";
        }
    }

    std::string UpperHorizontal()
    {
        switch (m_mode) {
        case Unicode:
            return "┬";
        case Ascii:
            return "+";
        }
    }

    std::string LowerHorizontal()
    {
        switch (m_mode) {
        case Unicode:
            return "┴";
        case Ascii:
            return "+";
        }
    }

    std::string Cross()
    {
        switch (m_mode) {
        case Unicode:
            return "┼";
        case Ascii:
            return "+";
        }
    }

private:
    CharacterMode m_mode;
};

}
