#include "types.h"

int	ai_select_line(game_board_t *b)
{
	uint_t	b_line = 0;
	uint_t	i = 0;

	while (i < b->max_lines) {
		if (b->remmatches_atl[b_line] < b->remmatches_atl[i]) {
			b_line = i;
		}
		i++;
	}
	return (b_line);
}

int	ai_select_nbmatches(game_board_t *b, uint_t sel_line)
{
	if (b->remmatches_atl[sel_line] < b->match_limit) {
		return ((b->remmatches_atl[sel_line] - b->match_limit));
	} else if (b->remmatches_atl[sel_line] == 2) {
		return (1);
	} else {
		return (b->match_limit);
	}
}

void	ai_get_input_choice(p_choice_t *c, game_board_t *b)
{
	c->line = ai_select_line(b);
	c->matches = ai_select_nbmatches(b, c->line);
}
