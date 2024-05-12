#include "Villager.hpp"

class Weaponsmith : public Villager {
public:
    Weaponsmith();
    virtual ~Weaponsmith();

    virtual std::size_t getIdentifier() const;
};
