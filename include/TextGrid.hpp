#pragma once

#include "TextCell.hpp"
#include "Types.hpp"
#include "Visibility.hpp"

#include <vector>

class USC_DLL_EXPORT TextGrid {
public:
    TextGrid() = default;
    TextGrid(u8 height, u8 width);

    // Create the cells with specified content
    void InitializeCells(i8 cell_content);

    // Print grid to console
    void Draw();

    // Resize cells
    void ResizeCells(u8 unit);

    // Set the content of a cell at (mxn) position
    void SetCell(u8 m, u8 n, i8 new_content);

    void Debug();

private:
    // Grid elements
    std::vector<std::vector<TextCell>> m_cells;
    // Grid dimensions (number of cells)
    u8 m_height { 0 }, m_width { 0 };
};
