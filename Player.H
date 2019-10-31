#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <map>
#include "Weapon.H"

namespace prs
{
  
  enum class Hand { Paper, Scissor, Rock, Last_Hand };

  class Player
  {
    public:
      Player( std::string name );
      std::string getName() { return name_; }
      virtual Weapon* getHand() = 0;
      void initWeapons( std::vector<Hand> weapons );
    protected:
      std::string name_;
      std::map<Hand, Weapon*> weapons_;
  };

  class HumanPlayer : public Player
  {
    public:
      HumanPlayer( std::string name );
      Weapon* getHand();
  };

  class ComputerPlayer : public Player
  {
    public:
      ComputerPlayer( std::string name );
      Weapon* getHand();
  };
}
#endif
