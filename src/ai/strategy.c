/*
** EPITECH PROJECT, 2018
** strategy.c
** File description:
** Strategy related functions for ai
*/

#include "types.h"
#include "checking.h"
#include "value_checks.h"

int	ai_select_nbmatches(game_board_t *b, uint_t sel_line)
{
	int	selected_matches = 0;
	int	is_last_line = check_for_last_line(b);
	int	sit_diff = (b->remmatches_atl[sel_line]);

	if (is_last_line && (b->remmatches_atl[sel_line] > 1)) {
		sit_diff--;
	} else if ((b->remmatches_atl[sel_line] <= b->match_limit)) {
		selected_matches = sit_diff;
	} else {
		selected_matches = b->match_limit;
	}
	return (selected_matches);
}

int	ai_select_line(game_board_t *b)
{
	uint_t	*rm = b->remmatches_atl;
	uint_t	idx = 0;
	uint_t	curr_lowest = b->max_width;
	int	i_lowest = 0;

	while (idx < b->max_lines) {
		if (rm[idx] <= curr_lowest && rm[idx] > 0) {
			curr_lowest = rm[idx];
			i_lowest = idx;
		}
		idx++;
	}
	return (i_lowest);
}

void	ai_get_input_choice(p_choice_t *c, game_board_t *b)
{
	c->line = ai_select_line(b);
	c->matches = ai_select_nbmatches(b, c->line);
}
