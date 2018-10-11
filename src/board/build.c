/*
** EPITECH PROJECT, 2018
** build.c
** File description:
** Board building related functions
*/

#include <stdlib.h>
#include "my.h"
#include "defs.h"
#include "types.h"
#include "helpers.h"
#include "pbuild.h"

game_board_t	*set_empty_board(game_board_t *board)
{
	board = malloc(sizeof(game_board_t));
	if (board == NULL) {
		board->status = ERROR;
		return (NULL);
	}
	board->remmatches_atl = NULL;
	board->display = NULL;
	board->status = EMPTY;
	return (board);
}

game_board_t	*init_board(int nb_lines, int match_limit)
{
	game_board_t	*board = NULL;

	if (nb_lines <= 1 || nb_lines >= 100 || match_limit < 1) {
		my_putstr_fd(2, "Error: Wrong options, quitting...\n");
		return (NULL);
	}
	board = set_empty_board(board);
	if (board == NULL) {
		my_putstr_fd(2, "Could not malloc the game board.\n");
		return (NULL);
	}
	board->max_lines = nb_lines;
	board->match_limit = match_limit;
	board = fill_board_sticks(board);
	map_board_display(board);
	return (board);
}
