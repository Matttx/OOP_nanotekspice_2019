##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for OOP_nanotekspice_2019
##
NAME			=		nanotekspice
LIB_NAME		=		libstring.a
TEST_NAME		=		tests/unit_tests

NO_COLOR		=		\e[0;0m
GREEN_COLOR		=		\e[0;32m
RED_COLOR		=		\e[0;31m
GREEN_B_COLOR	=		\e[1;32m
RED_B_COLOR		=		\e[1;31m

AR				=		ar rc
CC				=		g++
RM				=		rm -rf

SRCDIR			=		src

MAIN_SRC		=		main.cpp

PROJ_SRC		=		$(SRCDIR)/prompt.cpp				\
						$(SRCDIR)/component/Component.cpp 	\
						$(SRCDIR)/component/SComponent.cpp	\
						$(SRCDIR)/component/c_4001.cpp		\
						$(SRCDIR)/component/c_4008.cpp		\
						$(SRCDIR)/component/c_4011.cpp		\
						$(SRCDIR)/component/c_4013.cpp		\
						$(SRCDIR)/component/c_4017.cpp		\
						$(SRCDIR)/component/c_4030.cpp		\
						$(SRCDIR)/component/c_4040.cpp		\
						$(SRCDIR)/component/c_4069.cpp		\
						$(SRCDIR)/component/c_4071.cpp		\
						$(SRCDIR)/component/c_4081.cpp		\
						$(SRCDIR)/component/c_4094.cpp		\
						$(SRCDIR)/component/c_4514.cpp		\
						$(SRCDIR)/component/c_4801.cpp		\
						$(SRCDIR)/component/c_2716.cpp		\
						$(SRCDIR)/component/c_input.cpp		\
						$(SRCDIR)/component/c_output.cpp	\
						$(SRCDIR)/component/c_clock.cpp		\
						$(SRCDIR)/component/c_true.cpp		\
						$(SRCDIR)/component/c_false.cpp		\
						$(SRCDIR)/circuit/Circuit.cpp		\
						$(SRCDIR)/parser/parser.cpp			\
						$(SRCDIR)/gate/Gate.cpp				\
						$(SRCDIR)/gate/Or.cpp				\
						$(SRCDIR)/gate/Nor.cpp				\
						$(SRCDIR)/gate/And.cpp				\
						$(SRCDIR)/gate/Nand.cpp				\
						$(SRCDIR)/gate/Xor.cpp				\
						$(SRCDIR)/gate/Not.cpp				\
						$(SRCDIR)/exception/UnknownFile.cpp	\
						$(SRCDIR)/exception/NoFilePart.cpp	\
						$(SRCDIR)/exception/InvalidChipset.cpp		\
						$(SRCDIR)/exception/TooManyElementLink.cpp	\
						$(SRCDIR)/exception/SameChipsetName.cpp		\
						$(SRCDIR)/exception/NonExistingPin.cpp		\
						$(SRCDIR)/exception/LinkWrongFormat.cpp		\
						$(SRCDIR)/exception/UndeclaredChipset.cpp	\
						$(SRCDIR)/exception/InputNoValue.cpp		\
						$(SRCDIR)/exception/NoOutput.cpp			\
						$(SRCDIR)/exception/NotLinkedOutput.cpp		\
						$(SRCDIR)/error_handling/chipset_name.cpp	\
						$(SRCDIR)/error_handling/error_handling.cpp	\
						$(SRCDIR)/error_handling/pin_error.cpp		\
						$(SRCDIR)/error_handling/input_value.cpp	\
						$(SRCDIR)/error_handling/linked_output.cpp	\
						


TEST_SRC		=		tests/test_or.cpp					\
						tests/test_and.cpp					\
						tests/test_nand.cpp					\
						tests/test_not.cpp					\
						tests/test_nor.cpp					\
						tests/test_xor.cpp					\

MAIN_OBJ		=		$(MAIN_SRC:.cpp=.o)

PROJ_OBJ		=		$(PROJ_SRC:.cpp=.o)

TEST_OBJ		=		$(TEST_SRC:.cpp=.o)

TEST_COV		=		$(PROJ_SRC:.cpp=.gcda)	\
						$(PROJ_SRC:.cpp=.gcno)	\
						$(TEST_SRC:.cpp=.gcda)	\
						$(TEST_SRC:.cpp=.gcno)	\


INCLUDE_DIR		=		"./"

CFLAGS			+=		-W -Wall -Wextra  -Iinclude -g3

MAKEFLAGS		+=		--silent

%.o:			%.cpp
				$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $< \
				&& echo "$< $(GREEN_COLOR)successfully compiled$(NO_COLOR)" \
				|| { echo "$< $(RED_COLOR)couldn't be compiled$(NO_COLOR)"; exit 1; }

all:			$(NAME)

$(NAME):		$(MAIN_OBJ) $(PROJ_OBJ)
				$(CC) $(MAIN_OBJ) $(PROJ_OBJ) $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(LDLIBS) \
				&& echo "$(GREEN_B_COLOR)$(NAME) successfully created$(NO_COLOR)" \
				|| { echo "$(RED_B_COLOR)$(NAME) couldn't be created$(NO_COLOR)"; exit 1; }

clean:
				$(RM) $(MAIN_OBJ) $(PROJ_OBJ)

fclean:			clean
				$(RM) $(NAME)


re:				fclean all

sweet:			all clean

debug:			CFLAGS += -g3
debug:			sweet

tests_run:		TEST_FLAG += -fprofile-arcs -ftest-coverage --coverage
tests_run:		CFLAGS += -fprofile-arcs -ftest-coverage --coverage
tests_run:		LDLIBS += -lgcov -lcriterion
tests_run:		$(PROJ_OBJ) $(TEST_OBJ)
				$(CC) $(PROJ_OBJ) $(TEST_OBJ) -o $(TEST_NAME) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) \
				&& echo "$(GREEN_B_COLOR)$(TEST_NAME) successfully created$(NO_COLOR)" \
				|| { echo "$(RED_B_COLOR)$(TEST_NAME) couldn't be created$(NO_COLOR)"; exit 1; }
				$(TEST_NAME) \
				&& echo "$(GREEN_B_COLOR)Unit tests passed successfully$(NO_COLOR)" \
				|| { echo "$(RED_B_COLOR)Unit tests did not pass successfully$(NO_COLOR)"; exit 1; }
				gcovr -b -e tests/

tests_clean:	clean
				$(RM) $(TEST_OBJ)
				$(RM) $(TEST_COV)

tests_fclean:	tests_clean
				$(RM) $(TEST_NAME)

tests_re:		tests_fclean tests_run

tests_sweet:	tests_run
				gcovr
				gcovr -b --exclude tests/
				make tests_clean

.PHONY:			all clean fclean re main main_clean main_fclean main_re sweet sweet_lib debug tests_run tests_clean tests_fclean tests_re tests_sweet