#include "TextCell.hpp"

#include <iostream>

void newline();

int main() {
  TextCell cell1('x');
  TextCell cell2('o');
  TextCell cell3('x');
  TextCell cell4('x');
  TextCell cell5('o');
  TextCell cell6('x');

  cell2.SetNeighbors(NeighborPosition::Left, true);
  cell3.SetNeighbors(NeighborPosition::Left, true);
  cell5.SetNeighbors(NeighborPosition::Left, true);
  cell6.SetNeighbors(NeighborPosition::Left, true);

  cell1.DrawFrame(CornerDraw::Left);
  cell2.DrawFrame(CornerDraw::None);
  cell3.DrawFrame(CornerDraw::Right);
  newline();
  cell1.DrawContent();
  cell2.DrawContent();
  cell3.DrawContent();
  newline();
  cell1.DrawFrame(CornerDraw::Left);
  cell2.DrawFrame(CornerDraw::None);
  cell3.DrawFrame(CornerDraw::Right);
  newline();
  cell4.DrawContent();
  cell5.DrawContent();
  cell6.DrawContent();
  newline();
  cell4.DrawFrame(CornerDraw::Left);
  cell5.DrawFrame(CornerDraw::None);
  cell6.DrawFrame(CornerDraw::Right);
  newline();

  return 0;
}

void newline() { std::cout << "\n"; }