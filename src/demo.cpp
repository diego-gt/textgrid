#include "Cell.hpp"

#include <iostream>

int main() {
    Cell c("hello");
    std::cout << "Cell demo:\n";
    std::cout << "left_border";
    c.Display();
    std::cout << "right_border\n";

    Cell d("hello", 10, text::Left);
    std::cout << "Cell demo:\n";
    std::cout << "left_border";
    d.Display();
    std::cout << "right_border\n";

    d.Realign(text::Right);
    std::cout << "Cell demo:\n";
    std::cout << "left_border";
    d.Display();
    std::cout << "right_border\n";

    d.AdjustWidth(20);
    d.Realign(text::Center);
    std::cout << "Cell demo:\n";
    std::cout << "left_border";
    d.Display();
    std::cout << "right_border\n";

    return 0;
}
