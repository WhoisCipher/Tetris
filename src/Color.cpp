#include "Color.h"

const Color pink      = {238, 55,  171, 255};
const Color red       = {245, 52,  52,  255};
const Color blue      = {52,  232, 245, 255};
const Color green     = {52,  245, 77,  255};
const Color yellow    = {193, 245, 52,  255};
const Color orange    = {226, 116, 17,  255};
const Color purple    = {175, 0,   175, 255};
const Color gray      = {70,  70,  70,  255};

std::vector<Color> GetColors(){
    return {gray, yellow, blue, red, green, orange, pink, purple};
}