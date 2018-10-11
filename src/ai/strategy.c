/*
** EPITECH PROJECT, 2018
** strategy.c
** File description:
** Strategy related functions for ai
*/

#include "types.h"
#include <stdlib.h>

int	random_iv(int min, int max)
{
	int	q = ((max + 1) - min);

	return (min + (random() % q));
}

int	int_lower(int val1, int val2)
{
	return ((val1 < val2) ? val1 : val2);
}

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

	lim = int_lower(b->match_limit, b->remmatches_atl[sel_line]);
	selected_matches = random_iv(1, lim);
	return (selected_matches);
}

int	check_for_last_line(game_board_t *b)
{
	uint_t	idx = 0;
	int	lines_w_matches = 0;

	while (idx < b->max_lines) {
		if (b->remmatches_atl[idx] > 0)
			lines_w_matches++;
		idx++;
	}
	return ((lines_w_matches == 1) ? 1 : 0);
}

int	aisrs_select_nbmatches(game_board_t *b, uint_t sel_line)
{
	int	selected_matches = 0;
	int	is_last_line = check_for_last_line(b);
	int	sit_diff = (b->remmatches_atl[sel_line]);

	if (is_last_line)
		sit_diff--;
	if ((b->remmatches_atl[sel_line] <= b->match_limit))
		selected_matches = sit_diff;
	else
		selected_matches = b->match_limit;
	return (selected_matches);
}

int	aisrs_select_line(game_board_t *b)
{
	uint_t	idx = 0;
	uint_t	curr_lowest = b->max_width;
	int	i_lowest = 0;

	while (idx < b->max_lines) {
		if (b->remmatches_atl[idx] < curr_lowest &&
		b->remmatches_atl[idx] > 0) {
			curr_lowest = b->remmatches_atl[idx];
			i_lowest = idx;
		}
		idx++;
	}
	return (i_lowest);
}

void	ai_get_input_choice(p_choice_t *c, game_board_t *b, int ai_lvl)
{
	if (ai_lvl == 0) {
		c->line = airand_select_line(b);
		c->matches = airand_select_nbmatches(b, c->line);
	} else if (ai_lvl == 1) {
		c->line = aisrs_select_line(b);
		c->matches = aisrs_select_nbmatches(b, c->line);
	}
}
