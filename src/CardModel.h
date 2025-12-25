#pragma once

#include <ncurses.h>
#include <string>
#include <vector>


class CardModel {
    private:
        // contents
        std::string title;
        std::string desc;
        std::vector<std::string> subTasks;

        // dimensions
        int h, w, x, y;
        
    public:
        CardModel();
        CardModel(std::string title, std::string desc, int h, int w, int x, int y);
        ~CardModel();
};
