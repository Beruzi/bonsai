#include "BoardView.h"

BoardView::BoardView(std::string name) : boardName(name), boardWindow(nullptr) { 
    initBoard(); 
}

BoardView::BoardView(BoardView&& other) noexcept {
    this->boardName = std::move(other.boardName);
    this->boardWindow = std::exchange(other.boardWindow, nullptr);
    this->columnViews = std::move(other.columnViews);
}

BoardView& BoardView::operator=(BoardView&& other) noexcept {
    if(this == &other) return *this;

    if(this->boardWindow) {
        delwin(boardWindow);
        boardWindow = nullptr;
    }

    boardName = std::move(other.boardName);
    boardWindow = std::exchange(other.boardWindow, nullptr);
    columnViews = std::move(other.columnViews);

    return *this;
}

BoardView::~BoardView() {
    if(boardWindow) delwin(boardWindow);
}

// ---------------------------------------------------

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


