#pragma once

#include "TextCell.hpp"
#include "Visibility.hpp"

#include <vector>

class USC_DLL_EXPORT TextGrid {
public:
  TextGrid() = default;
  TextGrid(int height, int width);

  // Create the cells with specified content
  void InitializeCells(char cell_content);

  // Print grid to console
  void Draw();

  // Resize cells
  void ResizeCells(unsigned int unit);

  void Debug();

private:
  // Grid elements
  std::vector<TextCell> m_cells;
  // Grid dimensions (number of cells)
  int m_height{0}, m_width{0};
};