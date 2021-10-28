#include "TextGrid.hpp"

int main() {
  TextGrid grid(5, 5);

  grid.InitializeCells('x');
  grid.ResizeCells(2);
  grid.Draw();
  grid.SetCell(1, 1, 'a');
  grid.SetCell(2, 2, 'b');
  grid.SetCell(1, 2, 'c');
  grid.SetCell(3, 3, 'd');
  grid.SetCell(5, 1, 'e');
  grid.Draw();

  return 0;
}