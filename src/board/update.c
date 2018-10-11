/*
** EPITECH PROJECT, 2018
** update.c
** File description:
** Board update related functions
*/

#include "types.h"
#include "messages.h"

void	remove_sticks(uint_t *remmatches, int *matches)
{
	if ((uint_t) *matches > *remmatches) {
		*matches = *remmatches;
	}
	*remmatches -= *matches;
}

void	remove_from_display(game_board_t *b, p_choice_t *c)
{
	uint_t	i = (b->max_width - 1);
	int	removed = 0;
	char	*line = b->display[c->line];

	while (line[i] == ' ') {
		i--;
	}
	while (removed < c->matches) {
		line[i] = ' ';
		i--;
		removed++;
	}
}

void	update_board_with(game_board_t *b, p_choice_t *c, turn_type_t type)
{
	remove_sticks(&b->remmatches_atl[c->line], &c->matches);
	remove_from_display(b, c);
	print_updated_board(c->matches, c->line, type);
}
