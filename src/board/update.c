#include "types.h"

void	remove_sticks(uint_t *remsticks, uint_t nbsticks)
{
	*remsticks -= nbsticks;
}

void	remove_from_display(char *display_line, uint_t nbsticks)
{
	uint_t	i = 0;
	uint_t	removed = 0;

	while (display_line[i] == ' ' && display_line[i] != '\0') {
		i++;
	}
	while (removed < nbsticks) {
		display_line[i] = ' ';
		i++;
		removed++;
	}
}

void	update_board_with(game_board_t *board, uint_t line, uint_t nbsticks)
{
	remove_sticks(&board->remsticks_atl[line], nbsticks);
	remove_from_display(board->display[line], nbsticks);
}
