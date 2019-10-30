#include <string>
#include <iostream>
#include <stdlib.h>

#include "Player.H"
#include "weapons.H"

using namespace simon;

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
      return getWeapon( Hand::Paper );
    case 'R':
    case 'r':
      return getWeapon( Hand::Rock );
    case 'S':
    case 's':
      return getWeapon( Hand::Scissor );
    default:
      // Should never get here
      return getWeapon( Hand::LAST_Hand );
  }
}

Weapon* Player::getWeapon( Hand hand ) 
{
  switch ( hand )
  {
    case Hand::Paper:
      return new Paper();
    case Hand::Rock:
      return new Rock();
    case Hand::Scissor:
      return new Scissor();
    default:
      return nullptr;
  }
}

Weapon* ComputerPlayer::getHand()
{
  int last = static_cast<std::underlying_type<Hand>::type>( Hand::LAST_Hand ) - 1;
  return getWeapon( Hand( rand() % last ) );
}
