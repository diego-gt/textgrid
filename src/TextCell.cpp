#include "TextCell.hpp"

#include <iostream>

TextCell::TextCell(char content) {
  m_content = content;
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
  std::cout << "\tSize: (" << m_width << ", " << m_height << ")\n";
  std::cout << "\tNeighbors\n";
  std::cout << "\t\tLeft: " << m_has_nb_left << "\n";
  std::cout << "\t\tRight: " << m_has_nb_right << "\n";
}
