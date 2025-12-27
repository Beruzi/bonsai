#include <ncurses.h>

#include "view/BoardView.h"

int main() {
    // ncurses setup
    initscr();
    cbreak();
    noecho();

    // stdscr stuff (print, W/H)
    int H, W;
    getmaxyx(stdscr, H, W);
    mvprintw(0, 0, "stdscr size: %d x %d (press any key)", H, W);
    box(stdscr, 0, 0);
    refresh(); // stdscr targetted refresh
               

    // TODO: DataManager()
    // TODO: LayoutManager() -- responsible for recompute layouts?
    BoardView board("My Board");

    int input;
    while((input = getch()) != 'q') {
        switch(input) {
            case 'C': 
                board.addColumn("Testing");
                break;
        }
        board.render();
        // propagate all changes using wnoutrefresh to virtual screen buffer, and then update the physical screen w/ doupdate()
        doupdate();
    }
    
    endwin();
    return 0;
}

