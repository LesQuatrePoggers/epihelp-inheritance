#include "Toolsmith.hpp"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Toolsmith, name_and_identifier, .init = cr_redirect_stdout)
{
    Toolsmith villager1;
    Toolsmith villager2;

    Villager *villager1_ptr = &villager1;
    Villager *villager2_ptr = &villager2;

    cr_assert_eq(villager1.getIdentifier(), 42);
    cr_assert_eq(villager2.getIdentifier(), 42);
    cr_assert_eq(villager1_ptr->getIdentifier(), 42);
    cr_assert_eq(villager2_ptr->getIdentifier(), 42);
    cr_assert_str_eq(villager1.getName().c_str(), "Toolsmith");
    cr_assert_str_eq(villager2.getName().c_str(), "Toolsmith");
}
