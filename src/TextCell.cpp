#include "TextCell.hpp"

#include <iostream>

TextCell::TextCell(char content) { m_content = content; }

void TextCell::Draw() {
  DrawFrame(CornerDraw::Both);
  DrawContent();
  DrawFrame(CornerDraw::Both);
}

void TextCell::DrawFrame(CornerDraw cd) {
  switch (cd) {
  case CornerDraw::Left:
    if (m_has_nb_left) {
      std::cout << m_hframe << m_hframe;
    } else {
      std::cout << m_corner << m_hframe << m_hframe;
    }
    break;

  case CornerDraw::Right:
    if (m_has_nb_left) {
      std::cout << m_hframe << m_corner;
    } else {
      std::cout << m_hframe << m_hframe << m_corner;
    }
    break;

  case CornerDraw::None:
    if (m_has_nb_left) {
      std::cout << m_hframe << m_hframe;
    } else {
      std::cout << m_hframe << m_hframe << m_hframe;
    }
    break;

  case CornerDraw::Both:
    if (m_has_nb_left) {
      std::cout << m_hframe << m_corner;
    } else {
      std::cout << m_corner << m_hframe << m_corner;
    }
    break;
  }
}

void TextCell::DrawContent() {
  // If we have a neighbor to the left, we'll use its right vframe
  // as our left vframe
  if (m_has_nb_left) {
    std::cout << m_content << m_vframe;
  } else {
    std::cout << m_vframe << m_content << m_vframe;
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

bool TextCell::HasNeighbor(NeighborPosition nbp) {
  switch (nbp) {
  case NeighborPosition::Left:
    return m_has_nb_left;
  case NeighborPosition::Right:
    return m_has_nb_right;
  case NeighborPosition::Up:
    return m_has_nb_up;
  case NeighborPosition::Down:
    return m_has_nb_down;
  }
}

void TextCell::Debug() {
  std::cout << "Current cell has:\n";
  // std::cout << "\tSize: (" << m_width << ", " << m_height << ")\n";
  std::cout << "Content: " << m_content << "\n";
  std::cout << "Neighbors\n";
  std::cout << "\tLeft: " << m_has_nb_left << "\tRight: " << m_has_nb_right
            << "\n";
  std::cout << "\tUp: " << m_has_nb_up << "\tDown: " << m_has_nb_down << "\n";
}