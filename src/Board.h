#pragma once

#include <ncurses.h>
#include <vector>



class Board {
    private:
        std::vector<WINDOW*> cards;

    public:
        Board();
        ~Board();

        WINDOW* addCard();
        void render();
    
};
