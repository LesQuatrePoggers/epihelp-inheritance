#include "Toolsmith.hpp"

#include <iostream>

Toolsmith::Toolsmith()
    : Villager()
{
    std::cout << "[Toolsmith] Constructor" << std::endl;

    this->_name = "Toolsmith";
}

std::size_t Toolsmith::getIdentifier() const
{
    return 42;
}
