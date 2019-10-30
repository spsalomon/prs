#ifndef WEAPONS_H
#define WEAPONS_H

#include <string>


namespace simon
{
  enum class Result { Win, Lose, Tie };

  class Rock;
  class Scissor;
  class Paper;

  class Weapon
  {
    public:
      virtual ~Weapon() = default;
      virtual Result accept( Weapon* weapon ) = 0;
      virtual Result beats( Paper* weapon ) = 0;
      virtual Result beats( Scissor* weapon ) = 0;
      virtual Result beats( Rock* weapon ) = 0;
      virtual std::string getWeaponName() = 0;
  };

  class Paper : public Weapon
  {
    public:
      Paper() {}
      Result accept( Weapon* weapon );
      Result beats( Paper* weapon );
      Result beats( Scissor* weapon );
      Result beats( Rock* weapon );
      std::string getWeaponName() { return name_; }
    private:
      std::string name_ = "Paper";
  };

  class Scissor : public Weapon
  {
    public:
      Scissor() {}
      Result accept( Weapon* weapon );
      Result beats( Paper* weapon );
      Result beats( Scissor* weapon );
      Result beats( Rock* weapon );
      std::string getWeaponName() { return name_; }
    private:
      std::string name_ = "Scissor";
  };

  class Rock : public Weapon
  {
    public:
      Rock() {}
      Result accept( Weapon* weapon );
      Result beats( Paper* weapon );
      Result beats( Scissor* weapon );
      Result beats( Rock* weapon );
      std::string getWeaponName() { return name_; }
    private:
      std::string name_ = "Rock";
  };
}
#endif
