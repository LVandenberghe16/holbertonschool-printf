##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile my_runner
##

ECHO = /bin/echo -e
DEFAULT = "\033[00m"
BOLD = "\e[1m"
RED = "\e[31m"
GREEN = "\e[32m"
LIGHT_BLUE = "\e[94m"
WHITE = "\e[1;37m"

SRC =	printf.c 			\
		character_flag.c 	\
		printing_functions.c 	\
		test/main.c

TEST_SRC = test/main.c

OBJ = $(SRC:.c=.o)

TEST_OBJ = $(TEST_SRC:.c=.o)

NAME = printf

CFLAGS = -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format
LDFLAGS = 

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) \
	&& $(ECHO) $(BOLD) $(GREEN)"Compilation réussie : "$(LIGHT_BLUE)"$(NAME)"$(DEFAULT) \
	|| $(ECHO) $(BOLD) $(RED)"Erreur de compilation !"$(DEFAULT)

debug: CFLAGS += -g
debug: re

clean:
	@rm -f $(OBJ) $(TEST_OBJ) \
	&& $(ECHO) $(BOLD) $(GREEN)"Nettoyage des fichiers objets."$(DEFAULT)

fclean: clean
	@rm -f $(NAME) unit_test \
	&& $(ECHO) $(BOLD) $(GREEN)"Nettoyage complet."$(DEFAULT)

re: fclean all

tests_run: clean
	@$(CC) -o unit_test $(SRC) $(TEST_SRC) -lcriterion --coverage $(CFLAGS) \
	&& $(ECHO) $(BOLD) $(GREEN)"Tests prêts à être exécutés."$(DEFAULT) \
	|| $(ECHO) $(BOLD) $(RED)"Erreur lors de la préparation des tests."$(DEFAULT)
	@./unit_test

%.o: %.c
	@$(CC) -c -o $@ $< $(CFLAGS) \
	&& $(ECHO) -n $(BOLD) $(GREEN)" [OK] " $(WHITE) $< $(DEFAULT) \
	|| $(ECHO) -n $(BOLD) $(RED)" [KO] "$(WHITE) $< $(DEFAULT)
