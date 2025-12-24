#include <ncurses.h>
#include <bits/stdc++.h>
using namespace std;

int main() {
    initscr();
    cbreak();
    noecho();

    start_color();
    use_default_colors();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);

    int H, W;
    getmaxyx(stdscr, H, W);
    mvprintw(0, 0, "stdscr size: %d x %d (press any key)", H, W);
    refresh();

    int h = 10, w = 10;
    int y = (H - h) / 2;
    int x = (W - w) / 2;

    WINDOW* myWindow = newwin(h, w, y, x);

    wattron(myWindow, COLOR_PAIR(1));
    box(myWindow, 0, 0);
    mvwprintw(myWindow, 1, 1, "hi");
    wattroff(myWindow, COLOR_PAIR(1));

    wrefresh(myWindow);

    getch();
    endwin();
    return 0;
}

