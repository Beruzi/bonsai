#pragma once

#include <ncurses.h>
#include <string>
#include <vector>

class ColumnView {
    private:
        std::string columnName;
        WINDOW* columnWindow;
        //std::vector<CardView> cards;
    public:
        ColumnView();
        ColumnView(WINDOW* boardWin, std::string name);
        ~ColumnView();
    

        void initColumn(WINDOW* boardWin);



        void render();

};
