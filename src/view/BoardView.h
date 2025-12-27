#pragma once

#include <ncurses.h>
#include <string>
#include <vector>
#include <utility>

#include "ColumnView.h"


class BoardView {
    private:
        std::string boardName;
        WINDOW* boardWindow;
        std::vector<ColumnView> columnViews;

    public:
        // Constructor
        BoardView(std::string name);

        // DISABLE Copy Semenatics
        BoardView(const BoardView& other) = delete;
        BoardView& operator=(const BoardView& other) = delete;

        // Move Semantics
        BoardView(BoardView&& other) noexcept;
        BoardView& operator=(BoardView&& other) noexcept;
        
        // Destructor
        ~BoardView();

        void initBoard();
        void addColumn(std::string colName);
        void render();
};
