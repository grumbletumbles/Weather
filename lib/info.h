#pragma once
#include "pictures.h"
#include <cmath>

const int PLUS = 0xBB;
const int MINUS = 0xBD;
const int N = 0x4E;
const int P = 0x50;
const int HOURS_IN_DAY = 24;
const int DAY_SPLIT = 6;
const int CELL_WIDTH = 29;

std::string Weathercode(size_t weathercode);

std::string GetPicture(const std::string& condition);

std::string GetMonth(size_t index);
