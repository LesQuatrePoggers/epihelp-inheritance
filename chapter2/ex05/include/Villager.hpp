#pragma once

#include <string>

class Villager {
public:
    Villager();

    virtual std::size_t getIdentifier() const;
    const std::string& getName() const;

protected:
    std::string _name;

private:
    std::size_t _identifier;
};
