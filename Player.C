#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>

#include "Player.H"
#include "Weapon.H"

using namespace prs;

Player::Player( std::string name )
  : name_( name )
{}

HumanPlayer::HumanPlayer( std::string name )
  : Player( name )
{}

ComputerPlayer::ComputerPlayer( std::string name )
  : Player( name )
{}

Weapon* HumanPlayer::getHand()
{
  char choice;
  std::cout << "Paper (P), Rock (R), or Scissor (S): ";
  std::cin >> choice;

  while ( choice != 'P' &&
          choice != 'p' &&
          choice != 'R' &&
          choice != 'r' &&
          choice != 'S' &&
          choice != 's' )
  {
    std::cout << "Input choices are (P, R, or S ).\n";
    std::cout << "Paper (P), Rock (R), or Scissor (S): ";
    std::cin >> choice;
  }

  switch ( choice )
  {
    case 'P':
    case 'p':
      return weapons_[Hand::Paper];
    case 'R':
    case 'r':
      return weapons_[Hand::Rock];
    case 'S':
    case 's':
      return weapons_[Hand::Scissor];
    default:
      // Should never get here
      return weapons_[Hand::Last_Hand];
  }
}

Weapon* ComputerPlayer::getHand()
{
  return weapons_[ Hand( rand() % weapons_.size() ) ];
}

void Player::initWeapons( std::vector<Hand> weapons )
{ 
  Weapon* hand;

  for ( auto weapon : weapons ) {
    switch ( weapon )
    {
      case Hand::Paper:
        hand = new Paper();
        break;
      case Hand::Rock:
        hand = new Rock();
        break;
      case Hand::Scissor:
        hand = new Scissor();
        break;
      default:
        hand = nullptr;
        break;
    }
    weapons_[weapon] = hand;

    std::cout << "loaded " << hand->getWeaponName() << std::endl;
  }
}
