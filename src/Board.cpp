#include "Board.h"



Board::Board() {}
    

Board::~Board() {
    for(auto& card : cards) {
        delwin(card);
    }
}


WINDOW* Board::addCard() {
    WINDOW* win = newwin(5, 5, 1, 1);
    cards.push_back(win);
    return win;
}


void Board::render() {
    for(auto& card : cards) {
        box(card, 0, 0);
        wrefresh(card);
    }
}
