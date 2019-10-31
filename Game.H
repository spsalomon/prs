#ifndef GAME_H
#define GAME_H

#include <memory>
#include "Player.H"

namespace prs
{
  class Weapon;
  class Player;

  class Game
  {
    public:
      Game( Player* p1, Player* p2, int numGames );
      void run();
      void updateWorld( Result result );
      Player* getWinner();
      std::string printStatistics();
    private:
      Player* p1_;
      Player* p2_;
      int numGamesToPlay_ = 0;
      std::vector<Weapon*> weapons_;

      Player* winner_ = nullptr;
      int numGamesSoFar_ = 0;
      bool done_ = false;
      int p1Score_ = 0;
      int p2Score_ = 0;
  };
}
#endif
