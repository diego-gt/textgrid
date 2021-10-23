#include "TextGrid.hpp"

#include <iostream>
#include <string>

TextGrid::TextGrid(double height, double width) {
  m_height = height;
  m_width  = width;
}

void TextGrid::Draw(bool print_corners) {
  m_cells.assign(m_height, std::vector<TextCell>());

  for (int i = 0; i < m_height; ++i) {
    m_cells[i].assign(m_width, TextCell(5));
  }

  if (print_corners) {
    std::cout << "implement: print corners\n";
  }

  for (size_t i = 0; i < m_cells.size(); ++i) {
    for (size_t j = 0; j < m_cells[i].size(); ++j) {
      if (j > 0) {
        m_cells[i][j].SetNeighbors(N_Left, true);
      }

      if (j < m_cells[i].size() - 1) {
        m_cells[i][j].SetNeighbors(N_Right, true);
      }

      m_cells[i][j].SetContentChar('x');
      m_cells[i][j].Init();
    }
  }

  std::cout << "cell line total: " << m_cells.size() << "\n";
  std::cout << "cells total: " << m_cells[0].size() << "\n";

  std::vector<std::string> lines(m_width, std::string());

  std::cout << "lines total: " << lines.size() << "\n";

  for (auto &cell_row : m_cells) {
    for (auto &cell : cell_row) {
      for (int i = 0; i < cell.Height(); ++i) {
        lines.at(i) += cell.LineAt(i);
      }
    }
  }

  std::cout << "lines total: " << lines.size() << "\n";

  for (const auto &line : lines) {
    std::cout << line << "\n";
  }
}