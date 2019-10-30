#include <iostream>
#include <memory>
#include <sstream>

#include "weapons.H"
#include "Game.H"

using namespace simon;

Game::Game( Player* p1, Player* p2, int numGames )
  : p1_( p1 )
  , p2_( p2 ) 
  , numGamesToPlay_( numGames )
{}

void Game::run()
{
  while ( !done_ )
  {
    Weapon* computerChoice = p1_->getHand();
    Weapon* humanChoice = p2_->getHand();
    std::cout << "Human chooses: " << humanChoice->getWeaponName() << std::endl;
    std::cout << "Computer chooses: " << computerChoice->getWeaponName() << std::endl;

    Result result = humanChoice->accept( computerChoice );
    updateWorld( result );
  }
}

Player* Game::getWinner()
{
  return winner_;
}

void Game::updateWorld( Result result )
{
  switch ( result )
  {
    case Result::Win:
      p1Score_++;
      std::cout << "Computer wins!\n";
      break;
    case Result::Lose:
      p2Score_++;
      std::cout << "Human wins!\n";
      break;
    default:
      std::cout << "Tie game!\n";
      break;
  }
  ++numGamesSoFar_;

  if ( numGamesSoFar_ >= numGamesToPlay_ ) {
    done_ = true;

    if ( p1Score_ > p2Score_ )
      winner_ = p1_;
    else if ( p1Score_ < p2Score_ ) 
      winner_ = p2_;
  }
}

std::string Game::printStatistics()
{
  std::ostringstream ss;
  ss << "Player1: " << p1_->getName() << "\t\tPlayer2: " << p2_->getName();
  ss << "\nPlayer1 Score: " << p1Score_ << "\t\tPlayer2 Score: " << p2Score_;
  return ss.str();
}
