#ifndef RENDER_H
#define RENDER_H
#include "conmanip.h"

#include <iostream>

/* Small utility class to render characters with color */

class Render {

public:
    /* Print text with requested colors and reset console colors */
    static void printSymbol(char symbol,
                            conmanip::console_text_colors textCol,
                            conmanip::console_bg_colors bgCol)
    {
        std::cout
                << settextcolor(textCol)
                << setbgcolor(bgCol)
                << symbol
                << settextcolor(conmanip::console_text_colors::white)
                << setbgcolor(conmanip::console_bg_colors::black);
    }

};


#endif // RENDER_H
