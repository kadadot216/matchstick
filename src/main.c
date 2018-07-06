/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main file for Matchstick
*/

#include <stdlib.h>
#include "my.h"
#include "prototypes.h"
#include "types.h"
#include "parsing.h"

int	main(int ac, char **av)
{
	game_board_t	*board = NULL;
	int	nb_lines = 0;
	int	stick_limit = 0;

	if (ac > 3 || ac < 3) {
		return (84);
	}
	nb_lines = parse_value(av[1]);
	stick_limit = parse_value(av[2]);
	if (nb_lines == -1 || stick_limit == -1) {
		return (84);
	}
	board = init_board(nb_lines, stick_limit);
	if (board == NULL || board->status == ERROR) {
		my_putstr_fd(2, "Error during the board setup.\n");
		return (84);
	}
	play_game(board);
	board = unset_board(board);
	return (0);
}
