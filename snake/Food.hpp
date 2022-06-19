#pragma once
#include <random>
#include "Player.hpp"

class Player;

class Food
{
public:
	Food(std::shared_ptr<Player>& ptrToPlayer);

	void changeFoodLocation() noexcept;
	void randomizeFoodLocation() noexcept;
	bool isFoodOnPlayer() const noexcept;

	const COORD& getCurrentLocationRef() const noexcept;

private:
	COORD currentLocation_;
        std::shared_ptr<Player> ptrToPlayer_;
	std::random_device rd;
};
