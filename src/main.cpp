#include <ncurses.h>

#include "Board.h"

int main() {
    // ncurses setup
    initscr();
    cbreak();
    noecho();

    // stdscr stuff (print, W/H)
    int H, W;
    getmaxyx(stdscr, H, W);
    mvprintw(0, 0, "stdscr size: %d x %d (press any key)", H, W);
    //box(stdscr, 0, 0);
    refresh(); // stdscr targetted refresh
               

    
    // Kanban Resources
    Board board;

    // main loop
    int input;
    while((input = getch()) != 'q') {
        switch(input) {
            case 'c': 
                // add new card
                board.addCard();
                break;
        }

        board.render();
    }

    endwin();
    return 0;
}

