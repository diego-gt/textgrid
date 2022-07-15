#pragma once

#include "Types.hpp"
#include "Visibility.hpp"

#include <string>
#include <vector>

// FIXME: I think a corner struct inside the TextCell,
// with each corner having a "display" flag could be a better solution to this.
enum class CornerDraw { Left,
    Right,
    None,
    Both };
enum class NeighborPosition { Left,
    Right,
    Up,
    Down };

class USC_DLL_EXPORT TextCell {
public:
    TextCell() = default;
    TextCell(i8 content);

    // Resize cell by unit, unit is positive and an integer
    // cell size will be calculated by 2(unit) + 1,
    // since we always want a odd number for size
    // default size is 1 unit which is 3
    void Resize(u16 unit);

    // Tell the cell if it has any neighbors,
    // because it's drawing is affected by them
    void SetNeighbors(NeighborPosition nbp, bool value);

    // Query the cell to see if it has a neighbor at position
    bool HasNeighbor(NeighborPosition nbp);

    // Draw (print) the cell to the console
    void Draw();

    // Draw the upper/lower frame with corners specified by CornerDraw
    void DrawFrame(CornerDraw cd);

    // Draw the content with side frames
    void DrawContent();

    void SetContent(i8 new_content);

    // debug
    void Debug();

private:
    // dimensions
    u16 m_width { 3 }, m_height { 3 };

    // size of cell (unit-based)
    u16 m_unit { 1 };

    // Padding is calculated by substracting 1 of the width for each corner.
    // So, if it has a left neighbor it will only have 1 corner (right)
    // And if not, it will have both corners.
    // But, since if we have a left neighbor we don't want to print the first
    // column of chars we can generalize this since in both conditions we'd want
    // to substract 2
    u16 m_padding { 1 };

    // Neighbours
    bool m_has_nb_left { false }, m_has_nb_right { false };
    bool m_has_nb_up { false }, m_has_nb_down { false };

    // Characters
    i8 m_content = ' ';
    i8 m_corner = '+';
    i8 m_vframe = '|';
    i8 m_hframe = '-';
};
