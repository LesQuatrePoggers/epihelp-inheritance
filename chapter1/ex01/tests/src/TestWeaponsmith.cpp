#include "Villager.hpp"
#include "Weaponsmith.hpp"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include <concepts>

Test(Weaponsmith, inherit_from_villager, .init = cr_redirect_stdout)
{
    Weaponsmith villager;

    cr_assert((std::derived_from<Weaponsmith, Villager>), "Weaponsmith should inherit from Villager");
}

Test(Weaponsmith, constructor, .init = cr_redirect_stdout)
{
    Weaponsmith villager;

    cr_assert_stdout_eq_str(
        "[Villager] Constructor\n[Weaponsmith] Constructor\n",
        "Weaponsmith constructor should print \"[Villager] Constructor\" and \"[Weaponsmith] Constructor\""
    );
}
