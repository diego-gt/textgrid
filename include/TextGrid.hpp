#pragma once

#include "TextCell.hpp"
#include "Visibility.hpp"

#include <vector>

class USC_DLL_EXPORT TextGrid {
public:
  TextGrid() = default;
  TextGrid(int height, int width);
  void Draw();

private:
  // Grid dimensions (number of cells)
  int m_height{0}, m_width{0};
  std::vector<std::vector<TextCell>> m_cells;
};