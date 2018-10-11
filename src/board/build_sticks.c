/*
** EPITECH PROJECT, 2018
** build_sticks.c
** File description:
** Board's sticks fields building related functions
*/

#include <stdlib.h>
#include "types.h"
#include "helpers.h"

static void	compute_nb_sticks(uint_t *sticks_tab, uint_t max_lines)
{
	uint_t	line = 0;
	uint_t	sticks = 1;

	while (line < max_lines) {
		sticks_tab[line] = sticks;
		sticks += 2;
		line++;
	}
}

game_board_t	*fill_board_sticks(game_board_t *board)
{
	board->remmatches_atl = malloc(sizeof(uint_t) * board->max_lines);
	compute_nb_sticks(board->remmatches_atl, board->max_lines);
	board->max_width = board->remmatches_atl[board->max_lines - 1];
	board->status = SET;
	return (board);
}
