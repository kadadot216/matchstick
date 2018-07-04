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

int	main(int ac, char **av)
{
	game_board_t	*board = NULL;
	int	nb_lines = 0;

	if (ac > 2) {
		return (84);
	}
	nb_lines = parse_nb_lines(av);
	board = init_board
	return (0);
}


