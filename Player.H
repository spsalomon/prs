#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "weapons.H"

namespace simon
{
  
  enum class Hand { Paper, Scissor, Rock, LAST_Hand };

  class Player
  {
    public:
      Player( std::string name );
      std::string getName() { return name_; }
      Weapon* getWeapon( Hand hand );
      virtual Weapon* getHand() = 0;
    private:
      std::string name_;
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
