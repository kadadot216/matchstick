/*
** EPITECH PROJECT, 2018
** build_map.c
** File description:
** Board's map building related functions
*/

#include <stdlib.h>
#include "types.h"
#include "my.h"

static void	map_board_line(char *line, uint_t width, uint_t nb_sticks)
{
	uint_t	i = 0;
	uint_t	start_offset = (width / 2) - (nb_sticks / 2);

	while (i < start_offset) {
		line[i] = ' ';
		i++;
	}
	while (i < start_offset + nb_sticks) {
		line[i] = '|';
		i++;
	}
	while (i < width) {
		line[i] = ' ';
		i++;
	}
	line[i] = '\0';
}

game_board_t	*map_board_display(game_board_t *b)
{
	int	j = 0;

	if (b == NULL || b->maxsticks_atl == NULL) {
		my_puterror("Error during display creation.\n");
		return (NULL);
	}
	b->display = malloc(sizeof(char *) * (b->max_lines + 1));
	while (j < b->max_lines) {
		b->display[j] = malloc(sizeof(char) * b->max_width);
		map_board_line(b->display[j], b->max_width,
			b->maxsticks_atl[j]);
		j++;
	}
	b->display[j] = NULL;
	return (b);
}
