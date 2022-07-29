#include "Cell.hpp"

#include <iostream>

int main() {
    Cell c("hello");
    std::cout << "Cell demo:\n";
    std::cout << text::borders.vertical.unicode;
    c.Display();
    std::cout << text::borders.vertical.unicode << '\n';

    Cell d("hello", 10, text::Left);
    std::cout << "Cell demo:\n";
    std::cout << text::borders.vertical.unicode;
    d.Display();
    std::cout << text::borders.vertical.unicode << '\n';

    d.Realign(text::Right);
    std::cout << "Cell demo:\n";
    std::cout << text::borders.vertical.unicode;
    d.Display();
    std::cout << text::borders.vertical.unicode << '\n';

    d.AdjustWidth(20);
    d.Realign(text::Center);
    std::cout << "Cell demo:\n";
    std::cout << text::borders.vertical.unicode;
    d.Display();
    std::cout << text::borders.vertical.unicode << '\n';

    return 0;
}
