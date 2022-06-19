#pragma once
#include <iostream>
#include <array>
#include <iomanip>
#include "Player.hpp"

class Player;
class Food;

class Board
{
public:
    Board(std::shared_ptr<Food> ptrToFood, std::shared_ptr<Player> ptrToPlayer);

    void draw() noexcept;
    void updateBoard() noexcept;
    void drawFrame() const noexcept;

private:
    std::shared_ptr<Player> ptrToPlayer_;
    std::shared_ptr<Food> ptrToFood_;
    std::array<std::array<char, WIDTH>, HEIGHT> board_;
};