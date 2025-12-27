#include "BoardView.h"

BoardView::BoardView() : boardName("Board"), boardWindow(nullptr) {
    initBoard();
}

BoardView::BoardView(std::string name) : boardName(name), boardWindow(nullptr) {
    initBoard();
}

BoardView::~BoardView() {
    delwin(boardWindow);
}


void BoardView::initBoard() {
    int H, W;
    getmaxyx(stdscr, H, W);

    boardWindow = newwin(H, W, 0, 0);
    box(boardWindow, 0, 0);
    mvwprintw(boardWindow, 0, 2, "%s", boardName.c_str());
}


void BoardView::addColumn(std::string colName) {
    columnViews.emplace_back(boardWindow, colName);
}

void BoardView::render() {
    wnoutrefresh(boardWindow);

    // propate refresh call to "child" components
    for(auto& col : columnViews) {
        col.render();
    }
}


