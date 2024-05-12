#include "Villager.hpp"

class Toolsmith : public Villager {
public:
    Toolsmith();
    virtual ~Toolsmith();

    virtual std::size_t getIdentifier() const;
};
