#include "TextCell.hpp"

#include <iostream>

TextCell::TextCell(char content) { m_content = content; }

void TextCell::Draw() {
  DrawFrame(CornerDraw::Both);
  std::cout << m_vframe << m_content << m_vframe << "\n";
  DrawFrame(CornerDraw::Both);
}

void TextCell::DrawFrame(CornerDraw cd) {
  switch (cd) {
  case CornerDraw::Left:
    std::cout << m_corner << m_hframe << m_hframe << "\n";
    break;

  case CornerDraw::Right:
    std::cout << m_hframe << m_hframe << m_corner << "\n";
    break;

  case CornerDraw::None:
    std::cout << m_hframe << m_hframe << m_hframe << "\n";
    break;

  case CornerDraw::Both:
    std::cout << m_corner << m_hframe << m_corner << "\n";
    break;
  }
}

void TextCell::SetNeighbors(NeighborPosition nbp, bool value) {
  switch (nbp) {
  case NeighborPosition::Left:
    m_has_nb_left = value;
    break;
  case NeighborPosition::Right:
    m_has_nb_right = value;
    break;
  case NeighborPosition::Up:
    m_has_nb_up = value;
    break;
  case NeighborPosition::Down:
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
