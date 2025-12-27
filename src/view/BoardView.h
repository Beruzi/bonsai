#pragma once

#include <ncurses.h>
#include <string>
#include <vector>

#include "ColumnView.h"


class BoardView {
    private:
        std::string boardName;
        WINDOW* boardWindow;
        std::vector<ColumnView> columnViews;

    public:
        // Constructor
        BoardView();
        BoardView(std::string name);


        // Copy & Copy Assignment Constructors
        

        // Move & Move Assignment Constructors


        // Destructor
        ~BoardView();

        void initBoard();


        void addColumn(std::string colName);

        void render();
};

