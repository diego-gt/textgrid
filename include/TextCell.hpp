#pragma once

#include "Visibility.hpp"

#include <string>
#include <vector>

enum CornerDraw { C_None, C_UpLeft, C_UpRight, C_DownLeft, C_DownRight };
enum NeighborPosition { N_Left, N_Right, N_Up, N_Down };

class USC_DLL_EXPORT TextCell {
public:
  TextCell() = default;
  TextCell(int size);

  void SetNeighbors(NeighborPosition nbp, bool value);

  // debug
  void Debug();

private:
  // Neighbours
  bool m_has_nb_left{false}, m_has_nb_right{false};
  bool m_has_nb_up{false}, m_has_nb_down{false};

  // Dimensions & positions
  int m_height{0}, m_width{0};
  int m_padding{0};
  int m_content_pos{0};

  // Characters
  char m_content = ' ';
  char m_corner  = '+';
  char m_vframe  = '|';
  char m_hframe  = '-';
};