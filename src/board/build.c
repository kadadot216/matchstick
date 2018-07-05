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
	board->maxsticks_atl = NULL;
	board->remsticks_atl = NULL;
	board->display = NULL;
	board->status = EMPTY;
	return (board);
}

game_board_t	*init_board(uint_t nb_lines)
{
	game_board_t	*board = NULL;	

	if (nb_lines < 1) {
		my_puterror("Error: wrong nb of lines\n");
		return (NULL);
	}
	board = set_empty_board(board);
	if (board == NULL) {
		my_puterror("Could not malloc the game board.\n");
		return (NULL);
	}
	board->max_lines = nb_lines;
	board = fill_board_sticks(board);
	map_board_display(board);
	return (board);
}
