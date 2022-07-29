#pragma once

#include "Utilities.hpp"
#include "Types.hpp"

#include <string>

class Cell {
public:
    Cell() = default;
    ~Cell() = default;

    Cell(const std::string& content) : m_content(content) {
        m_width = m_content.size() + 2;
        m_padding_left = 1;
        m_padding_right = 1;
    }

    Cell(const std::string& content, u8 width, text::HorizontalAlignment alignment) : m_content(content), m_alignment(alignment) {
        m_width = width;
        Realign(alignment);
    }

    void Realign(text::HorizontalAlignment alignment);
    void AdjustWidth(u8 width);
    void Display();
private:
    // TODO: only accept trimmed content.
    std::string m_content;
    text::HorizontalAlignment m_alignment = text::Center;
    u8 m_width;
    u8 m_padding_left, m_padding_right;
};
