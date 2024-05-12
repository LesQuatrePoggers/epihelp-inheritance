#include "Villager.hpp"

class Toolsmith : public Villager {
public:
    Toolsmith();

    virtual std::size_t getIdentifier() const;
};
