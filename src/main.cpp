#include "TextGrid.hpp"

#include <iostream>

void newline();

int main() {
  TextGrid grid(1, 1);

  grid.InitializeCells('x');
  grid.Debug();
  grid.Draw();

  return 0;
}

void newline() { std::cout << "\n"; }