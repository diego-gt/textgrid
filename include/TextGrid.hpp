#pragma once

#include "TextCell.hpp"
#include "Visibility.hpp"

#include <vector>

class USC_DLL_EXPORT TextGrid {
public:
  TextGrid() = default;
  TextGrid(unsigned short height, unsigned short width);

  // Create the cells with specified content
  void InitializeCells(char cell_content);

  // Print grid to console
  void Draw();

  // Resize cells
  void ResizeCells(unsigned short unit);

  // Set the content of a cell at (mxn) position
  void SetCell(unsigned short m, unsigned short n, char new_content);

  void Debug();

private:
  // Grid elements
  std::vector<std::vector<TextCell>> m_cells;
  // Grid dimensions (number of cells)
  unsigned short m_height{0}, m_width{0};
};