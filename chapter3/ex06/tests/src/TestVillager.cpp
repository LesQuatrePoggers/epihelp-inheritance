#include "Villager.hpp"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Villager, name_and_identifier, .init = cr_redirect_stdout)
{
    {
        Villager villager1;
        Villager villager2;

        cr_assert_neq(villager1.getIdentifier(), villager2.getIdentifier());
        cr_assert_str_eq(villager1.getName().c_str(), "Villager");
        cr_assert_str_eq(villager2.getName().c_str(), "Villager");
    }

    cr_assert_stdout_eq_str(
        "[Villager] Constructor\n"
        "[Villager] Constructor\n"
        "[Villager] Destructor\n"
        "[Villager] Destructor\n"
    );
}
