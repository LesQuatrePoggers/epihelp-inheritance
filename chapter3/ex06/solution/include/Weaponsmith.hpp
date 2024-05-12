#include "Villager.hpp"

class Weaponsmith : public virtual Villager {
public:
    Weaponsmith();
    virtual ~Weaponsmith();

    virtual std::size_t getIdentifier() const;
};
