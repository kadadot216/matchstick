/*
** EPITECH PROJECT, 2018
** value_checks.c
** File description:
** Value checking related functions
*/

#include "types.h"
#include "defs.h"
#include "error_fcts.h"

int	check_for_invalid_prompt(int value)
{
	if (value == ERR_EOF)
		return (value);
	if (value < 0) {
		print_error_invalid_prompt();
		return (-1);
	}
	return (value);
}

int	line_is_valid(int value, uint_t max_lines)
{
	value = check_for_invalid_prompt(value);
	if (value == 0 || value > ((int) max_lines)) {
		print_error_line_oor();
		return (0);
	}
	return (value);
}

int	matches_are_valid(int value, uint_t remmatches, uint_t limit)
{
	value = check_for_invalid_prompt(value);
	if (value == 0) {
		print_error_no_matches();
		return (-1);
	} else if (remmatches == 0) {
		print_error_not_enough_matches();
		return (-1);
	} else if (value > ((int) limit)) {
		print_error_matches_oob(limit);
		return (-1);
	}
	return (value);
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
