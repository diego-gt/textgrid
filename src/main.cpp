#include "TextGrid.hpp"

int main() {
  TextGrid grid(5, 5);

  grid.InitializeCells('x');
  //grid.Debug();
  grid.Draw();

  return 0;
}