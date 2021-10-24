#pragma once

#include "Visibility.hpp"

#include <string>
#include <vector>

enum class CornerDraw { Left, Right, None, Both };
enum class NeighborPosition { Left, Right, Up, Down };

class USC_DLL_EXPORT TextCell {
public:
  TextCell() = default;
  TextCell(char content);

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

  // debug
  void Debug();

private:
  // dimensions
  int m_width{3}, m_height{3};

  // Neighbours
  bool m_has_nb_left{false}, m_has_nb_right{false};
  bool m_has_nb_up{false}, m_has_nb_down{false};

  // Characters
  char m_content = ' ';
  char m_corner  = '+';
  char m_vframe  = '|';
  char m_hframe  = '-';
};