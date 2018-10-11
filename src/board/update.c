#include "types.h"
#include "messages.h"

void	remove_sticks(uint_t *remmatches, int *matches)
{
	if ((uint_t) *matches > *remmatches) {
		*matches = *remmatches;
	}
	*remmatches -= *matches;
}

void	remove_from_display(char *display_line, uint_t matches)
{
	uint_t	i = 0;
	uint_t	removed = 0;

	while (display_line[i] == ' ' && display_line[i] != '\0') {
		i++;
	}
	while (removed < matches) {
		display_line[i] = ' ';
		i++;
		removed++;
	}
}

void	update_board_with(game_board_t *b, p_choice_t *c, turn_type_t type)
{
	remove_sticks(&b->remmatches_atl[c->line], &c->matches);
	remove_from_display(b->display[c->line], c->matches);
	print_updated_board(c->matches, c->line, type);
}
