#include "Player.hpp"

Player::Player() : currentDirection_(Direction::Right), currentHead_(WIDTH/4, HEIGHT/2)
{
    for (int i = 0; i < 4; i++)
    {
        player_.push_back(COORD((WIDTH / 4) - i, HEIGHT / 2));
    }
}

void Player::changePosition() noexcept
{
    switch (static_cast<int>(currentDirection_))
    {
    case 0:
        player_.push_front({ currentHead_.coordX_, currentHead_.coordY_-- });
        if (!isFoodEaten())
        {
            player_.pop_back();
        }
        break;
    case 1:
        player_.push_front({ currentHead_.coordX_, currentHead_.coordY_++ });
        if (!isFoodEaten())
        {
            player_.pop_back();
        }
        break;
    case 2:
        player_.push_front({ currentHead_.coordX_--, currentHead_.coordY_ });
        if (!isFoodEaten())
        {
            player_.pop_back();
        }
        break;
    case 3:
        player_.push_front({ currentHead_.coordX_++, currentHead_.coordY_ });
        if (!isFoodEaten())
        {
            player_.pop_back();
        }
        break;
    }
}
bool Player::checkIfLost() const noexcept
{
    for(const auto& el : player_)
    {
        if (currentHead_.coordX_ == el.coordX_ && currentHead_.coordY_ == el.coordY_)
        {
            return true;
        }
    }
    if (currentHead_.coordX_ < 0 || currentHead_.coordX_ >= WIDTH || currentHead_.coordY_ < 0 || currentHead_.coordY_ >= HEIGHT)
    {
        return true;
    }
    return false;
}
bool Player::isFoodEaten() const noexcept
{
    if (player_.at(0).coordX_ == ptrToFood_->getCurrentLocationRef().coordX_ && player_.at(0).coordY_ == ptrToFood_->getCurrentLocationRef().coordY_)
    {
        ptrToFood_->changeFoodLocation();
        return true;
    }
    return false;
}

const std::deque<COORD>& Player::getPlayerRef()  noexcept
{
    return player_;
}
const Direction& Player::getDirectionRef() const noexcept
{
    return currentDirection_;
}
const size_t Player::getPlayerSize() const noexcept
{
    return player_.size();
}

void Player::setDirection(const Direction& newDirection) noexcept
{
    currentDirection_ = newDirection;
}
void Player::setPointerToFood(const std::shared_ptr<Food>& ptrToFood) noexcept
{
    ptrToFood_ = ptrToFood;
}
