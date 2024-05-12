#include "Villager.hpp"

class Toolsmith : public virtual Villager {
public:
    Toolsmith();
    virtual ~Toolsmith();

    virtual std::size_t getIdentifier() const;
};
