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
  for (int i = 0; i < m_height; i++) {
    /// TODO: add support for multiple rows
    for (int j = 0; j < m_width; j++) {
      // every cell besides the first has a left neighbor
      if (j > 0) {
        m_cells[j + (i * m_width)].SetNeighbors(NeighborPosition::Left, true);
      }

      m_cells[j + (i * m_width)].SetNeighbors(NeighborPosition::Right, true);

      // every cell besides the last has a right neighbor
      if (j == m_width - 1) {
        m_cells[j + (i * m_width)].SetNeighbors(NeighborPosition::Right, false);
      }

      // if there's more than 1 row, we have neighbors above
      if (i > 0) {
        m_cells[j + (i * m_width)].SetNeighbors(NeighborPosition::Up, true);
      }

      // if there's more than 1 row, every row besides the last one will have
      // neighbors below
      if (i < m_height - 1) {
        m_cells[j + (i * m_width)].SetNeighbors(NeighborPosition::Down, true);
      }
    }
  }
}

void TextGrid::Draw() {
  for (int i = 0; i < m_height; i++) {
    for (int j = 0; j < m_width; j++) {
      // draw frames
      if (!m_cells[j + (i * m_width)].HasNeighbor(NeighborPosition::Up)) {
        if (j == 0) {
          if (j == m_width - 1) {
            m_cells[j + (i * m_width)].DrawFrame(CornerDraw::Both);
            std::cout << "\n";
          } else {
            m_cells[j + (i * m_width)].DrawFrame(CornerDraw::Left);
          }
        } else if (j == m_width - 1) {
          m_cells[j + (i * m_width)].DrawFrame(CornerDraw::Right);
          std::cout << "\n";
        } else {
          m_cells[j + (i * m_width)].DrawFrame(CornerDraw::None);
        }
      }
    }

    for (int j = 0; j < m_width; j++) {
      m_cells[j + (i * m_width)].DrawContent();
      if (j == m_width - 1) {
        std::cout << "\n";
      }
    }

    for (int j = 0; j < m_width; j++) {
      if (!m_cells[j + (i * m_width)].HasNeighbor(NeighborPosition::Down)) {
        if (j == 0) {
          if (j == m_width - 1) {
            m_cells[j + (i * m_width)].DrawFrame(CornerDraw::Both);
          } else {
            m_cells[j + (i * m_width)].DrawFrame(CornerDraw::Left);
          }
        } else if (j == m_width - 1) {
          m_cells[j + (i * m_width)].DrawFrame(CornerDraw::Right);
          std::cout << "\n";
        } else {
          m_cells[j + (i * m_width)].DrawFrame(CornerDraw::None);
        }
      } else {
        // if there's a neighbor below, don't print any corners
        m_cells[j + (i * m_width)].DrawFrame(CornerDraw::None);
        if (j == m_width - 1) {
          std::cout << "\n";
        }
      }
    }
  }
}

void TextGrid::Debug() {
  for (int i = 0; i < m_height; i++) {
    std::cout << "Row " << i << " cells:\n";
    for (int j = 0; j < m_width; j++) {
      m_cells[j + (i * m_width)].Debug();
    }
  }
}