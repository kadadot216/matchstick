/*
** EPITECH PROJECT, 2018
** user_prompt.c
** File description:
** Player's prompt related functions
*/

#include <stdlib.h>
#include "types.h"
#include "my.h"
#include "error_fcts.h"
#include "value_checks.h"
#include "user_prompt.h"

int	get_line_input(game_board_t *board)
{
	int	value = 0;

	while (value <= 0 || value == (-42)) {
		my_putstr_fd(1, "Line: ");
		value = ask_number();
		value = line_is_valid(value, board->max_lines);
	}
	return ((value - 1));
}

int	get_matches_input(game_board_t *board, uint_t line)
{
	int	value = 0;

	while (value == 0 || value == (-42)) {
		my_putstr_fd(1, "Matches: ");
		value = ask_number();
		value = matches_are_valid(value, board->remmatches_atl[line],
			board->match_limit);
	}
	return (value);
}
