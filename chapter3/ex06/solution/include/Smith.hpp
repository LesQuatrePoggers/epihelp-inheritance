#pragma once

#include "Toolsmith.hpp"
#include "Weaponsmith.hpp"

class Smith : public Toolsmith, public Weaponsmith {
public:
    Smith();
    virtual ~Smith();

    virtual std::size_t getIdentifier() const;
};
