#include "Toolsmith.hpp"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Toolsmith, name_and_identifier, .init = cr_redirect_stdout)
{
    Toolsmith villager1;
    Toolsmith villager2;

    cr_assert_neq(villager1.getIdentifier(), villager2.getIdentifier());
    cr_assert_str_eq(villager1.getName().c_str(), "Toolsmith");
    cr_assert_str_eq(villager2.getName().c_str(), "Toolsmith");
}
