#pragma once

#include "Visibility.hpp"

#include <string>
#include <vector>

enum CornerDraw { C_None, C_UpLeft, C_UpRight, C_DownLeft, C_DownRight };
enum NeighborPosition { N_Left, N_Right, N_Up, N_Down };

class USC_DLL_EXPORT TextCell {
public:
  TextCell() = default;
  TextCell(char content);

  void SetNeighbors(NeighborPosition nbp, bool value);

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