#include "Smith.hpp"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include <concepts>

Test(Smith, inherits, .init = cr_redirect_stdout)
{
    cr_assert((std::derived_from<Smith, Villager>));
    cr_assert((std::derived_from<Smith, Toolsmith>));
    cr_assert((std::derived_from<Smith, Weaponsmith>));
}

Test(Smith, name_and_identifier, .init = cr_redirect_stdout)
{
    {
        Smith villager1;
        Smith villager2;

        Villager *villager1_ptr = &villager1;
        Villager *villager2_ptr = &villager2;

        cr_assert_eq(villager1.getIdentifier(), 84);
        cr_assert_eq(villager2.getIdentifier(), 84);
        cr_assert_eq(villager1_ptr->getIdentifier(), 84);
        cr_assert_eq(villager2_ptr->getIdentifier(), 84);
        cr_assert_str_eq(villager1.getName().c_str(), "Weaponsmith");
        cr_assert_str_eq(villager2.getName().c_str(), "Weaponsmith");
    }

    cr_assert_stdout_eq_str(
        "[Villager] Constructor\n"
        "[Toolsmith] Constructor\n"
        "[Weaponsmith] Constructor\n"
        "[Smith] Constructor\n"
        "[Villager] Constructor\n"
        "[Toolsmith] Constructor\n"
        "[Weaponsmith] Constructor\n"
        "[Smith] Constructor\n"
        "[Smith] Destructor\n"
        "[Weaponsmith] Destructor\n"
        "[Toolsmith] Destructor\n"
        "[Villager] Destructor\n"
        "[Smith] Destructor\n"
        "[Weaponsmith] Destructor\n"
        "[Toolsmith] Destructor\n"
        "[Villager] Destructor\n"
    );
}
