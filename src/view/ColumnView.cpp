#include "ColumnView.h"

ColumnView::ColumnView(WINDOW* boardWin, std::string name)  : columnName(name) {
    initColumn(boardWin);
}

ColumnView::ColumnView(ColumnView&& other) noexcept {
    columnName = std::move(other.columnName);
    columnWindow = std::exchange(other.columnWindow, nullptr);
    //cards = std::move(other.column);
}

ColumnView& ColumnView::operator=(ColumnView&& other) noexcept {
    if(this == &other) return *this;

    if(columnWindow) {
        delwin(columnWindow);
        columnWindow = nullptr;
    }

    columnName = std::move(other.columnName);
    columnWindow = std::exchange(other.columnWindow, nullptr);
    //cards = std::move(other.column);

    return *this;
}


ColumnView::~ColumnView() {
    delwin(columnWindow);
}


// ----------------------------------------------------------------
void ColumnView::initColumn(WINDOW* boardWin) {
    int maxH, maxW;
    getmaxyx(boardWin, maxH, maxW);

    columnWindow = derwin(boardWin, maxH-2, maxW/4, 1, 1);

    box(columnWindow, 0, 0);
    mvwprintw(columnWindow, 1, 1, "%s", columnName.c_str());
}

//void addColumn(std::string colName) {}


void ColumnView::render() {
    wnoutrefresh(columnWindow);
}
