#pragma once

#include "TextCell.hpp"
#include "Visibility.hpp"

#include <vector>

class USC_DLL_EXPORT TextGrid {
public:
  TextGrid() = default;
  TextGrid(double height, double width);
  void Draw(bool print_corners);

private:
  // Grid dimensions (number of cells)
  double m_height{0}, m_width{0};
  std::vector<std::vector<TextCell>> m_cells;
};