#include "Smith.hpp"

#include <iostream>

Smith::Smith()
    : Villager(), Toolsmith(), Weaponsmith()
{
    std::cout << "[Smith] Constructor" << std::endl;

    // The name will be the one from the last class in the inheritance list
    // that overrides the _name attribute
}

Smith::~Smith()
{
    std::cout << "[Smith] Destructor" << std::endl;
}

std::size_t Smith::getIdentifier() const
{
    return 84;
}
