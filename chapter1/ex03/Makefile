EX_NAME := ex03
EX_SRC := $(shell find src -name "*.cpp")
EX_OBJ := $(EX_SRC:src/%.cpp=build/ex/obj/%.o)
EX_DEP := $(EX_SRC:src/%.cpp=build/ex/dep/%.d)
EX_CPPFLAGS := -iquote include
EX_CXXFLAGS := -std=c++20 -Wall -Wextra -Werror -O0 -g

EX_TESTS_SRC := $(shell find tests -name "*.cpp")
EX_TESTS_OBJ := $(EX_TESTS_SRC:tests/src/%.cpp=build/tests/ex/obj/%.o)
EX_TESTS_DEP := $(EX_TESTS_SRC:tests/src/%.cpp=build/tests/ex/dep/%.d)
EX_TESTS_CPPFLAGS := -iquote include -iquote tests/include
EX_TESTS_CXXFLAGS := -std=c++20 -Wall -Wextra -Werror --coverage

SOLUTION_NAME := solution_ex03
SOLUTION_SRC := $(shell find solution/src -name "*.cpp")
SOLUTION_OBJ := $(SOLUTION_SRC:solution/src/%.cpp=build/solution/obj/%.o)
SOLUTION_DEP := $(SOLUTION_SRC:solution/src/%.cpp=build/solution/dep/%.d)
SOLUTION_CPPFLAGS := -iquote solution/include
SOLUTION_CXXFLAGS := -std=c++20 -Wall -Wextra -Werror -O0 -g

SOLUTION_TESTS_SRC := $(shell find tests -name "*.cpp")
SOLUTION_TESTS_OBJ := $(SOLUTION_TESTS_SRC:tests/src/%.cpp=build/tests/solution/obj/%.o)
SOLUTION_TESTS_DEP := $(SOLUTION_TESTS_SRC:tests/src/%.cpp=build/tests/solution/dep/%.d)
SOLUTION_TESTS_CPPFLAGS := -iquote solution/include -iquote tests/include
SOLUTION_TESTS_CXXFLAGS := -std=c++20 -Wall -Wextra -Werror --coverage

LDFLAGS :=
LDLIBS  := -lcriterion -lgcov

all: $(EX_NAME)

solution_run: $(SOLUTION_NAME)
	@./$(SOLUTION_NAME)

tests_run: $(EX_NAME)
	@./$(EX_NAME)

clean:
	@rm -rf build

fclean: clean
	@rm -f $(EX_NAME) $(SOLUTION_NAME)

re:
	@$(MAKE) -s fclean
	@$(MAKE) -s all

.PHONY: all solution_run tests_run clean fclean re

$(EX_NAME): $(EX_OBJ) $(EX_TESTS_OBJ)
	@g++ -o $@ $^ $(LDFLAGS) $(LDLIBS)

$(SOLUTION_NAME): $(SOLUTION_OBJ) $(SOLUTION_TESTS_OBJ)
	@g++ -o $@ $^ $(LDFLAGS) $(LDLIBS)

build/ex/obj/%.o: src/%.cpp build/ex/dep/%.d
	@mkdir -p $(dir $@)
	@mkdir -p $(dir build/ex/dep/$*.d)
	@printf "%b\n" "\033[34mCompiling $<...\033[0m"
	@gcc -c $< -o $@ $(EX_CPPFLAGS) $(EX_CXXFLAGS) \
		-MT $@ -MMD -MP -MF build/ex/dep/$*.d

build/solution/obj/%.o: solution/src/%.cpp build/solution/dep/%.d
	@mkdir -p $(dir $@)
	@mkdir -p $(dir build/solution/dep/$*.d)
	@printf "%b\n" "\033[34mCompiling $<...\033[0m"
	@gcc -c $< -o $@ $(SOLUTION_CPPFLAGS) $(SOLUTION_CXXFLAGS) \
		-MT $@ -MMD -MP -MF build/solution/dep/$*.d

build/tests/ex/obj/%.o: tests/src/%.cpp build/tests/ex/dep/%.d
	@mkdir -p $(dir $@)
	@mkdir -p $(dir build/tests/ex/dep/$*.d)
	@printf "%b\n" "\033[34mCompiling $<...\033[0m"
	@gcc -c $< -o $@ $(EX_TESTS_CPPFLAGS) $(EX_TESTS_CXXFLAGS) \
		-MT $@ -MMD -MP -MF build/tests/ex/dep/$*.d

build/tests/solution/obj/%.o: tests/src/%.cpp build/tests/solution/dep/%.d
	@mkdir -p $(dir $@)
	@mkdir -p $(dir build/tests/solution/dep/$*.d)
	@printf "%b\n" "\033[34mCompiling $<...\033[0m"
	@gcc -c $< -o $@ $(SOLUTION_TESTS_CPPFLAGS) $(SOLUTION_TESTS_CXXFLAGS) \
		-MT $@ -MMD -MP -MF build/tests/solution/dep/$*.d

$(EX_DEP) $(EX_TESTS_DEP) $(SOLUTION_DEP) $(SOLUTION_TESTS_DEP):

-include $(EX_DEP)
-include $(TESTS_DEP)
-include $(SOLUTION_DEP)
-include $(SOLUTION_TESTS_DEP)
