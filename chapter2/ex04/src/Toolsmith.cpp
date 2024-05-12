#include "Toolsmith.hpp"

#include <iostream>

Toolsmith::Toolsmith()
    : Villager()
{
    std::cout << "[Toolsmith] Constructor" << std::endl;

    this->_name = "Toolsmith";
}
