/*
** EPITECH PROJECT, 2018
** destroy.c
** File description:
** Game board destruction related functions
*/

#include <stdlib.h>
#include "types.h"
#include "helpers.h"
#include "my.h"

game_board_t	*unset_board(game_board_t *b)
{
	b->maxsticks_atl = ms_free_uinttab(b->maxsticks_atl, b->max_lines);
	b->remsticks_atl = ms_free_uinttab(b->remsticks_atl, b->max_lines);
	b->display = ms_free_strtab(b->display, b->max_lines, b->max_width);
	b->max_lines = 0;
	b->max_width = 0;
	b->status = 0;
	free(b);
	b = NULL;
	return (b);
}
