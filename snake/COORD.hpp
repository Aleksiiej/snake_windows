#pragma once
#include "Board.hpp"

struct COORD
{
    COORD() = default;
    COORD(const int& X, const int& Y) : coordX_(X), coordY_(Y)
    {}

    int coordX_;
    int coordY_;
};