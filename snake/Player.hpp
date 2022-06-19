#pragma once
#include <deque>
#include "GlobalValues.hpp"
#include "COORD.hpp"
#include "Food.hpp"

class Player
{
public:
    Player();

    void changePosition() noexcept;
    bool checkIfLost() const noexcept;
    bool isFoodEaten() const noexcept;

    const std::deque<COORD>& getPlayerRef() noexcept;
    const Direction& getDirectionRef() const noexcept;
    const size_t getPlayerSize() const noexcept;

    void setDirection(const Direction& newDirection) noexcept;
    void setPointerToFood(const std::shared_ptr<Food>&) noexcept;

private:
    std::deque<COORD> player_;
    COORD currentHead_;
    Direction currentDirection_;
    std::shared_ptr<Food> ptrToFood_;
};