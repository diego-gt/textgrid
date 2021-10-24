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
