#include "TextCell.hpp"

#include <iostream>

TextCell::TextCell(int size) {
  if (size % 2 == 0) {
    std::cout << "The cell size should be odd for alignment, adding 1...\n";
    ++size;
  }

  m_height      = size;
  m_width       = size;
  m_padding     = (size - 1) / 2;
  m_content_pos = m_padding;
}

void TextCell::SetNeighbors(NeighborPosition nbp, bool value) {
  switch (nbp) {
  case NeighborPosition::N_Left:
    m_has_nb_left = value;
    break;
  case NeighborPosition::N_Right:
    m_has_nb_right = value;
    break;
  case NeighborPosition::N_Up:
    m_has_nb_up = value;
    break;
  case NeighborPosition::N_Down:
    m_has_nb_down = value;
    break;
  }
}

void TextCell::SetCornerChar(char corner) { m_corner = corner; }
void TextCell::SetContentChar(char content) { m_content = content; }

void TextCell::Init() {
  int def_width = m_width;

  int padding_size = m_padding - 1;

  std::string side_pad = std::string(padding_size, ' ');

  if (m_has_nb_left) {
    def_width = m_width - 1;
  }

  std::string full_pad_rightframe = std::string(def_width - 1, ' ') + m_vframe;
  std::string full_pad_bothframes =
      m_vframe + std::string(def_width - 2, ' ') + m_vframe;

  // ceiling
  m_lines.push_back(std::string(def_width, m_hframe));

  // between lines
  for (int i = 1; i < m_height - 1; i++) {
    if (i == m_content_pos) {
      // content line
      if (m_has_nb_left) {
        m_lines.push_back(side_pad + m_content + side_pad + m_vframe);
      } else {
        m_lines.push_back(m_vframe + side_pad + m_content + side_pad +
                          m_vframe);
      }
    } else {
      if (m_has_nb_left) {
        m_lines.push_back(full_pad_rightframe);
      } else {
        m_lines.push_back(full_pad_bothframes);
      }
    }
  }

  // floor
  m_lines.push_back(std::string(def_width, m_hframe));
}

void TextCell::PrintLineAt(int index) {
  std::cout << m_lines[index] << std::endl;
}

std::string TextCell::LineAt(int index) { return m_lines[index]; }

void TextCell::Debug() {
  std::cout << "Current cell has:\n";
  std::cout << "\t"
            << "Size: (" << m_width << ", " << m_height << ")\n";
  std::cout << "\t"
            << "Neighbors"
            << "\n";
  std::cout << "\t\t"
            << "Left: " << m_has_nb_left << "\n";
  std::cout << "\t\t"
            << "Right: " << m_has_nb_right << "\n";
  // std::cout << "\t\t"
  //           << "Up: " << m_has_nb_up << "\n";
  // std::cout << "\t\t"
  //           << "Down: " << m_has_nb_down << "\n";
}

void TextCell::PrintStraightLine(int width, CornerDraw cd) {
  switch (cd) {
  case CornerDraw::C_None:
    if (!m_has_nb_left) {
      std::cout << std::string(width, m_hframe);
    } else {
      std::cout << std::string(width - 1, m_hframe);
    }
    break;
  case CornerDraw::C_UpLeft:
  case CornerDraw::C_DownLeft:
    if (!m_has_nb_left) {
      std::cout << m_corner << std::string(width - 1, m_hframe);
    } else {
      std::cout << m_corner << std::string(width - 2, m_hframe);
    }
    break;
  case CornerDraw::C_UpRight:
  case CornerDraw::C_DownRight:
    if (!m_has_nb_left) {
      std::cout << std::string(width - 1, m_hframe) << m_corner;
    } else {
      std::cout << std::string(width - 2, m_hframe) << m_corner;
    }
    break;
  }
}

void TextCell::PrintPaddedLine() {
  if (!m_has_nb_left) {
    std::cout << m_vframe << std::string(m_width - 2, ' ') << m_vframe;
  } else {
    std::cout << std::string(m_width - 1, ' ') << m_vframe;
  }
}

void TextCell::PrintContent() {
  if (m_has_nb_left) {
    std::cout << std::string(m_padding - 1, ' ') << m_content
              << std::string(m_padding - 1, ' ') << m_vframe;
  } else {
    std::cout << m_vframe << std::string(m_padding - 1, ' ') << m_content
              << std::string(m_padding - 1, ' ') << m_vframe;
  }
}
