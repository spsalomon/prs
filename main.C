#include <iostream>
#include <string>
#include<bits/stdc++.h> 

#include "weapons.H"

#include "Game.H"
#include "Player.H"

using namespace simon;

int main() 
{
  std::string name;
  int numGames;

  std::cout << "Welcome to Paper, Rocks, and Scissors Game.\n";
  std::cout << "In this game you will be playing against a computer.\n";
  std::cout << "Human, please enter your name: ";
  std::cin >> name;
  std::cout << "How many games do you want to play against the computer (Note: You will get to play at least one game)? ";
  std::cin >> numGames;

  while ( !std::cin.good() ) {
    std::cin.clear();
    std::cin.ignore( INT_MAX, '\n' );
    std::cout << "Input must be an integer.\nHow many games do you want to play against the computer? ";
    std::cin >> numGames;
  }

  std::unique_ptr<Player> human = std::unique_ptr<HumanPlayer>( new HumanPlayer( name ) );
  std::unique_ptr<Player> computer = std::unique_ptr<ComputerPlayer>( new ComputerPlayer( "Computer" ) );
  std::unique_ptr<Game> game = std::unique_ptr<Game>( new Game( computer.get(), human.get(), numGames ) );

  game->run();

  Player* winner = game->getWinner();
  if ( winner )
  {
    std::cout << "The Match Winner is `" << winner->getName() << "`.\n";
  }
  else {
    std::cout << "There was no winner. Match ended in a tie!\n";
  }

  std::cout << "\n\n----------Game Statistics----------\n";
  std::cout << game->printStatistics() << std::endl;
  std::cout << "\n\nThank you for playing!\n";

  return 0;
}
