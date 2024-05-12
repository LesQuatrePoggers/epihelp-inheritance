#include "Weaponsmith.hpp"

#include <iostream>

Weaponsmith::Weaponsmith()
    : Villager()
{
    std::cout << "[Weaponsmith] Constructor" << std::endl;

    this->_name = "Weaponsmith";
}

Weaponsmith::~Weaponsmith()
{
    std::cout << "[Weaponsmith] Destructor" << std::endl;
}

std::size_t Weaponsmith::getIdentifier() const
{
    return 69;
}
