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

void	ms_uinttabcpy(uint_t *dest, uint_t *src, uint_t size)
{
	uint_t	i = 0;

	while (i < size) {
		dest[i] = src[i];
		i++;
	}
}

void	compute_nb_sticks(uint_t *sticks_tab, uint_t max_lines)
{
	uint_t	line = 0;	
	uint_t	sticks = 1;

	while (line < max_lines) {
		sticks_tab[line] = sticks;
		sticks += 2;
		line++;
	}
}

void	map_board_line(char *display_line, uint_t line_width, uint_t nb_sticks)
{
	uint_t	i = 0;
	uint_t	start_offset = (line_width / 2) - (nb_sticks / 2);

	while (i < start_offset) {
		display_line[i] = ' ';
		i++;
	}
	while (i < start_offset + nb_sticks) {
		display_line[i] = '|';
		i++;
	}
	while (i < line_width) {
		display_line[i] = ' ';
		i++;
	}
	display_line[i] = '\0';
}

game_board_t	*map_board_display(game_board_t *board)
{
	int	j = 0;

	if (board == NULL || board->maxsticks_atl == NULL) {
		my_puterror("Error during display creation.\n");
		return (NULL);
	}
	board->display = malloc(sizeof(char *) * (board->max_lines + 1));
	while (j < board->max_lines) {
		board->display[j] = malloc(sizeof(char) * board->max_width);
		map_board_line(board->display[j], board->max_width, board->maxsticks_atl[j]);
		j++;
	}
	board->display[j] = NULL;
	return (board);
}

game_board_t	*fill_board_sticks(game_board_t *board)
{
	board->maxsticks_atl = malloc(sizeof(uint_t) * board->max_lines);
	board->remsticks_atl = malloc(sizeof(uint_t) * board->max_lines);
	compute_nb_sticks(board->maxsticks_atl, board->max_lines);
	ms_uinttabcpy(board->remsticks_atl, board->maxsticks_atl,
		board->max_lines);
	board->max_width = board->maxsticks_atl[board->max_lines - 1];
	map_board_display(board);
	board->status = SET;
	return (board);
}

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
		my_puterror ("Could not malloc the game board.\n");
		return (NULL);
	}
	board->max_lines = nb_lines;
	board = fill_board_sticks(board);
	return (board);
}
