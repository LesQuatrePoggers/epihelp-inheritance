#include "Villager.hpp"

class Toolsmith : public Villager {
public:
    Toolsmith();

    std::size_t getIdentifier() const;
};
