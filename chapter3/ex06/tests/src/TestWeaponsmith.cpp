#include "Weaponsmith.hpp"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Weaponsmith, name_and_identifier, .init = cr_redirect_stdout)
{
    {
        Weaponsmith villager1;
        Weaponsmith villager2;

        Villager *villager1_ptr = &villager1;
        Villager *villager2_ptr = &villager2;

        cr_assert_eq(villager1.getIdentifier(), 69);
        cr_assert_eq(villager2.getIdentifier(), 69);
        cr_assert_eq(villager1_ptr->getIdentifier(), 69);
        cr_assert_eq(villager2_ptr->getIdentifier(), 69);
        cr_assert_str_eq(villager1.getName().c_str(), "Weaponsmith");
        cr_assert_str_eq(villager2.getName().c_str(), "Weaponsmith");
    }

    cr_assert_stdout_eq_str(
        "[Villager] Constructor\n"
        "[Weaponsmith] Constructor\n"
        "[Villager] Constructor\n"
        "[Weaponsmith] Constructor\n"
        "[Weaponsmith] Destructor\n"
        "[Villager] Destructor\n"
        "[Weaponsmith] Destructor\n"
        "[Villager] Destructor\n"
    );
}
