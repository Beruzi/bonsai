#include "CardModel.h"


CardModel::CardModel() : title("title"), desc("desc"), h(0), w(0), x(0), y(0) {}

CardModel::CardModel(std::string title, std::string desc, int h, int w, int x, int y) : 
    title(title), desc(desc), h(h), w(w), x(x), y(y) {}

CardModel::~CardModel() {}
