#include "Cell.hpp"
#include "Utilities.hpp"

#include <iostream>

int main()
{
    Cell d("hello", 10, text::Left);
    text::Corner crn(text::Unicode);
    text::ConnectedCorner conncrn(text::Unicode);
    text::Border brd(text::Unicode);

    // top border
    std::cout << crn.UpperLeft();
    std::cout << text::RepeatString(d.width(), brd.Horizontal());
    std::cout << conncrn.UpperHorizontal();
    std::cout << text::RepeatString(d.width(), brd.Horizontal());
    std::cout << crn.UpperRight();
    std::cout << '\n';

    // content
    std::cout << brd.Vertical();
    d.Display();
    std::cout << brd.Vertical();
    d.Display();
    std::cout << brd.Vertical();
    std::cout << '\n';

    // top border
    std::cout << conncrn.UpperLeftVertical();
    std::cout << text::RepeatString(d.width(), brd.Horizontal());
    std::cout << conncrn.Cross();
    std::cout << text::RepeatString(d.width(), brd.Horizontal());
    std::cout << conncrn.UpperRightVertical();
    std::cout << '\n';

    // content
    std::cout << brd.Vertical();
    d.Display();
    std::cout << brd.Vertical();
    d.Display();
    std::cout << brd.Vertical();
    std::cout << '\n';

    // bottom border
    std::cout << crn.LowerLeft();
    std::cout << text::RepeatString(d.width(), brd.Horizontal());
    std::cout << conncrn.LowerHorizontal();
    std::cout << text::RepeatString(d.width(), brd.Horizontal());
    std::cout << crn.LowerRight();
    std::cout << '\n';
    return 0;
}
