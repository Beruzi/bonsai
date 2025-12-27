#include "ColumnView.h"

ColumnView::ColumnView() : columnName("status"), columnWindow(nullptr) {}

ColumnView::ColumnView(WINDOW* boardWin, std::string name)  : columnName(name) {
    initColumn(boardWin);
}

ColumnView::~ColumnView() {
    delwin(columnWindow);
}


void ColumnView::initColumn(WINDOW* boardWin) {
    int maxH, maxW;
    getmaxyx(boardWin, maxH, maxW);

    columnWindow = derwin(boardWin, maxH-2, maxW/4, 1, 1);

    box(columnWindow, 0, 0);
    mvwprintw(columnWindow, 1, 1, "%s", columnName.c_str());
}


void ColumnView::render() {
    wnoutrefresh(columnWindow);
    // propagte to cards
}
