#include "TextGrid.hpp"

#include <iostream>
#include <string>

TextGrid::TextGrid(unsigned short height, unsigned short width) {
  m_height = height;
  m_width  = width;
}

void TextGrid::InitializeCells(char cell_content) {
  // create the cells
  for (int i = 0; i < m_height; i++) {
    m_cells.push_back(std::vector<TextCell>());
    for (int j = 0; j < m_width; j++) {
      m_cells[i].push_back(TextCell(cell_content));
    }
  }

  // Neighbor configuration
  for (int i = 0; i < m_height; i++) {
    for (int j = 0; j < m_width; j++) {
      TextCell *cell = &m_cells[i][j];
      // every cell besides the first has a left neighbor
      if (j > 0) {
        cell->SetNeighbors(NeighborPosition::Left, true);
      }

      cell->SetNeighbors(NeighborPosition::Right, true);

      // every cell besides the last has a right neighbor
      if (j == m_width - 1) {
        cell->SetNeighbors(NeighborPosition::Right, false);
      }

      // if there's more than 1 row, we have neighbors above
      if (i > 0) {
        cell->SetNeighbors(NeighborPosition::Up, true);
      }

      // if there's more than 1 row, every row besides the last one will have
      // neighbors below
      if (i < m_height - 1) {
        cell->SetNeighbors(NeighborPosition::Down, true);
      }
    }
  }
}

void TextGrid::Draw() {
  for (int i = 0; i < m_height; i++) {
    for (int j = 0; j < m_width; j++) {
      // Get cell handle
      TextCell *cell = &m_cells[i][j];

      // draw frames
      if (!cell->HasNeighbor(NeighborPosition::Up)) {
        if (j == 0) {
          if (j == m_width - 1) {
            cell->DrawFrame(CornerDraw::Both);
            std::cout << "\n";
          } else {
            cell->DrawFrame(CornerDraw::Left);
          }
        } else if (j == m_width - 1) {
          cell->DrawFrame(CornerDraw::Right);
          std::cout << "\n";
        } else {
          cell->DrawFrame(CornerDraw::None);
        }
      }
    }

    for (int j = 0; j < m_width; j++) {
      // Get cell handle
      TextCell *cell = &m_cells[i][j];

      cell->DrawContent();
      if (j == m_width - 1) {
        std::cout << "\n";
      }
    }

    for (int j = 0; j < m_width; j++) {
      // Get cell handle
      TextCell *cell = &m_cells[i][j];

      if (!cell->HasNeighbor(NeighborPosition::Down)) {
        if (j == 0) {
          if (j == m_width - 1) {
            cell->DrawFrame(CornerDraw::Both);
          } else {
            cell->DrawFrame(CornerDraw::Left);
          }
        } else if (j == m_width - 1) {
          cell->DrawFrame(CornerDraw::Right);
          std::cout << "\n";
        } else {
          cell->DrawFrame(CornerDraw::None);
        }
      } else {
        // if there's a neighbor below, don't print any corners
        cell->DrawFrame(CornerDraw::None);
        if (j == m_width - 1) {
          std::cout << "\n";
        }
      }
    }
  }
}

void TextGrid::ResizeCells(unsigned short unit) {
  for (auto &row : m_cells) {
    for (auto &cell : row) {
      cell.Resize(unit);
    }
  }
}

void TextGrid::SetCell(unsigned short m, unsigned short n, char new_content) {
  m_cells[m - 1][n - 1].SetContent(new_content);
}

void TextGrid::Debug() {
  unsigned int idx = 0;
  for (auto &row : m_cells) {
    std::cout << "Row " << idx << " cells: \n";
    for (auto &cell : row) {
      cell.Debug();
    }
    idx++;
  }
}