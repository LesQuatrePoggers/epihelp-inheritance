#include "Villager.hpp"

#include <iostream>

Villager::Villager()
{
    std::cout << "[Villager] Constructor" << std::endl;

    static std::size_t identifier = 0;
    this->_identifier = identifier++;
    this->_name = "Villager";
}

std::size_t Villager::getIdentifier() const
{
    return this->_identifier;
}

const std::string& Villager::getName() const
{
    return this->_name;
}
