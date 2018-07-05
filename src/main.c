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
	uint_t	nb_lines = 0;

	if (ac > 2) {
		return (84);
	}
	nb_lines = parse_nb_lines(av);
	board = init_board(nb_lines);
	if (board == NULL || board->status == ERROR) {
		my_puterror("Error during the board setup.\n");
		return (84);
	}
	play_game(board);
	board = unset_board(board);
	return (0);
}
