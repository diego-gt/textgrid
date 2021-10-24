#include "TextGrid.hpp"

#include <iostream>
#include <string>

TextGrid::TextGrid(int height, int width) {
  m_height = height;
  m_width  = width;
}

void TextGrid::InitializeCells(char cell_content) {
  // Create cells
  for (int i = 0; i < m_height * m_width; i++) {
    m_cells.push_back(TextCell(cell_content));
  }

  // Neighbor configuration
  for (int h = 0; h < m_height; h++) {
    /// TODO: add support for multiple rows
    for (int i = 0; i < m_width; i++) {
      // every cell besides the first has a left neighbor
      if (i > 0) {
        m_cells[i].SetNeighbors(NeighborPosition::Left, true);
      }

      m_cells[i].SetNeighbors(NeighborPosition::Right, true);
      // every cell besides the last has a right neighbor
      if (i == m_width - 1) {
        m_cells[i].SetNeighbors(NeighborPosition::Right, false);
      }
    }
  }
}

void TextGrid::Draw() {
  /// TODO: add support for multiple rows

  // Stage 1: Draw upper frame
  for (int i = 0; i < m_width; i++) {
    if (i == 0) {
      m_cells[i].DrawFrame(CornerDraw::Left);
    } else if (i == m_width - 1) {
      m_cells[i].DrawFrame(CornerDraw::Right);
    } else {
      m_cells[i].DrawFrame(CornerDraw::None);
    }
  }

  std::cout << "\n";

  // Stage 2: Draw content
  for (auto &cell : m_cells) {
    cell.DrawContent();
  }

  std::cout << "\n";

  // Stage 3: Draw lower frame
  for (int i = 0; i < m_width; i++) {
    if (i == 0) {
      m_cells[i].DrawFrame(CornerDraw::Left);
    } else if (i == m_width - 1) {
      m_cells[i].DrawFrame(CornerDraw::Right);
    } else {
      m_cells[i].DrawFrame(CornerDraw::None);
    }
  }

  std::cout << "\n";
}

void TextGrid::Debug() {
  for (auto &cell : m_cells) {
    cell.Debug();
  }
}