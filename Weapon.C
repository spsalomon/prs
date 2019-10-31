#include <iostream>

#include "Weapon.H"

using namespace prs;

Result Paper::accept( Weapon* weapon )
{
  return weapon->beats( this );
}

Result Scissor::accept( Weapon* weapon )
{
  return weapon->beats( this );
}

Result Rock::accept( Weapon* weapon )
{
  return weapon->beats( this );
}

Result Paper::beats( Paper* weapon ) 
{
  std::cout << name_ << " vs. " << weapon->getWeaponName() << std::endl;

  return Result::Tie;
}

Result Paper::beats( Scissor* weapon )
{
  std::cout << name_ << " vs. " << weapon->getWeaponName() << std::endl;
  return Result::Lose;
}

Result Paper::beats( Rock* weapon )
{
  std::cout << name_ << " vs. " << weapon->getWeaponName() << std::endl;
  return Result::Win;
}

Result Scissor::beats( Paper* weapon ) 
{
  std::cout << name_ << " vs. " << weapon->getWeaponName() << std::endl;
  return Result::Win;
}

Result Scissor::beats( Scissor* weapon )
{
  std::cout << name_ << " vs. " << weapon->getWeaponName() << std::endl;
  return Result::Tie;
}

Result Scissor::beats( Rock* weapon )
{
  std::cout << name_ << " vs. " << weapon->getWeaponName() << std::endl;
  return Result::Lose;
}

Result Rock::beats( Paper* weapon ) 
{
  std::cout << name_ << " vs. " << weapon->getWeaponName() << std::endl;
  return Result::Lose;
}

Result Rock::beats( Scissor* weapon )
{
  std::cout << name_ << " vs. " << weapon->getWeaponName() << std::endl;
  return Result::Win;
}

Result Rock::beats( Rock* weapon )
{
  std::cout << name_ << " vs. " << weapon->getWeaponName() << std::endl;
  return Result::Tie;
}
