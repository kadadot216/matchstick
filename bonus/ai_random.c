/*
** EPITECH PROJECT, 2018
** ai_random.c
** File description:
** AI Random strategy
*/

#include "ai.h"
#include "checking.h"

int	airand_select_line(game_board_t *b)
{
	uint_t	b_line = 0;
	int	line_not_empty = 0;

	while (!line_not_empty) {
		b_line = random_iv(0, (b->max_lines - 1));
		line_not_empty = b->remmatches_atl[b_line];
	}
	return (b_line);
}

int	airand_select_nbmatches(game_board_t *b, uint_t sel_line)
{
	int	lim = 0;
	int	selected_matches = 0;

	lim = int_lowest(b->match_limit, b->remmatches_atl[sel_line]);
	selected_matches = random_iv(1, lim);
	return (selected_matches);
}

void	airand_get_input_choice(p_choice_t *c, game_board_t *b)
{
	c->line = airand_select_line(b);
	c->matches = airand_select_nbmatches(b, c->line);
}
