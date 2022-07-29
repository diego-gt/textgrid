#include "Cell.hpp"

#include <cmath>
#include <iostream>
#include <string>

void Cell::Realign(text::HorizontalAlignment alignment) {
    u8 total_padding = m_width - m_content.size();
    u8 current_padding = m_padding_left + m_padding_right;
    
    // If there's no change in padding or alignment, don't do anything
    if (current_padding == total_padding && m_alignment == alignment) {
        return;
    }

    m_alignment = alignment;

    switch (m_alignment) {
        case text::Center:
            if (total_padding % 2 == 0) {
                m_padding_left = total_padding / 2;
                m_padding_right = total_padding / 2;
            } else {
                // when uneven, shift slightly to the left
                m_padding_left = std::floor(total_padding / 2);
                m_padding_right = std::floor(total_padding / 2) + 1;
            }
            break;
        case text::Left:
            m_padding_left = 1;
            m_padding_right = total_padding - 1;
            break;
        case text::Right:
            m_padding_left = total_padding - 1;
            m_padding_right = 1;
            break;
    }
}

void Cell::AdjustWidth(u8 width) {
    // wrapping is not supported yet.
    if (m_width != width && width > m_content.size()) {
        m_width = width;
        Realign(m_alignment);
    } else {
        return;
    }
}

void Cell::Display() {
    std::cout << std::string(m_padding_left, ' ') << m_content << std::string(m_padding_right, ' ');
}
