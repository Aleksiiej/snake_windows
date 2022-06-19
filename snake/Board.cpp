#include "Board.hpp"

Board::Board(std::shared_ptr<Food> ptrToFood, std::shared_ptr<Player> ptrToPlayer)
    : ptrToFood_(ptrToFood), ptrToPlayer_(ptrToPlayer)
{
    std::for_each(begin(board_), end(board_), [](auto& el) {el.fill('.'); });
}

void Board::draw() noexcept
{
    system("cls");
    updateBoard();
    drawFrame();
    for (const auto& outerArray : board_)
    {
        std::cout << "|";
        std::for_each(begin(outerArray), end(outerArray), [](const auto& el) { std::cout << std::setw(2) << el; });
        std::cout << std::setw(2) << "|" << std::endl;
    }
    drawFrame();
    std::cout << "Score: " << ptrToPlayer_->getPlayerSize() - 4 << std::endl;
}
void Board::updateBoard() noexcept
{
    board_.at(ptrToPlayer_->getPlayerRef().front().coordY_).at(ptrToPlayer_->getPlayerRef().front().coordX_) = '@';
    board_.at(ptrToPlayer_->getPlayerRef().back().coordY_).at(ptrToPlayer_->getPlayerRef().back().coordX_) = '.';
    board_.at(ptrToFood_->getCurrentLocationRef().coordY_).at(ptrToFood_->getCurrentLocationRef().coordX_) = '#';
}
void Board::drawFrame() const noexcept
{
    std::cout << "+";
    for (int i = 0; i < WIDTH; i++)
    {
        std::cout << std::setw(2) << "=";
    };
    std::cout << " +" << std::endl;
}
