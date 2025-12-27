#pragma once

#include <ncurses.h>
#include <string>
#include <vector>
#include <utility>

class ColumnView {
    private:
        std::string columnName;
        WINDOW* columnWindow;
        //std::vector<CardView> cards;
        
    public:
        // construcotr
        ColumnView(WINDOW* boardWin, std::string name);

        // DISABLE copy semantics
        ColumnView(const ColumnView& other) = delete;
        ColumnView& operator=(const ColumnView& other) = delete;

        // move semantics
        ColumnView(ColumnView&& other) noexcept;
        ColumnView& operator=(ColumnView&& other) noexcept;

        // destructor
        ~ColumnView();
    

        void initColumn(WINDOW* boardWin);
        void render();
};
