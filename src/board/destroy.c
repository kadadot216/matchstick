/*
** EPITECH PROJECT, 2018
** destroy.c
** File description:
** Game board destruction related functions
*/

#include <stdlib.h>
#include "types.h"
#include "my.h"

uint_t	*ms_free_uinttab(uint_t *tab, uint_t size)
{
	uint_t	i = 0;

	while (i < size) {
		tab[i] = 0;
		i++;
	}
	free(tab);
	tab = NULL;
	return (tab);
}

char	**ms_free_strtab(char **display, uint_t height, uint_t width)
{
	int	j = 0;

	while (j < height) {
		my_memset(display[j], '\0', width);
		free(display[j]);
		display[j] = NULL;
		j++;
	}
	free(display);
	display = NULL;
	return (display);
}

game_board_t	*unset_board(game_board_t *board)
{
	board->maxsticks_atl = ms_free_uinttab(board->maxsticks_atl, board->max_lines);
	board->remsticks_atl = ms_free_uinttab(board->remsticks_atl, board->max_lines);
	board->display = ms_free_strtab(board->display, board->max_lines, board->max_width);
	board->max_lines = 0;
	board->max_width = 0;
	board->status = 0;
	free(board);
	board = NULL;
	return (board);
}
