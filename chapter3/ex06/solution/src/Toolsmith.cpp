#include "Toolsmith.hpp"

#include <iostream>

Toolsmith::Toolsmith()
    : Villager()
{
    std::cout << "[Toolsmith] Constructor" << std::endl;

    this->_name = "Toolsmith";
}

Toolsmith::~Toolsmith()
{
    std::cout << "[Toolsmith] Destructor" << std::endl;
}

std::size_t Toolsmith::getIdentifier() const
{
    return 42;
}
