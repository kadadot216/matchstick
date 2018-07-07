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

prompt_error_t	check_for_incorrect_input(int value, int lim1, int lim2)
{
	if (value < 0) {
		return (INVALID_PROMPT);
	} else if (value == 0 && lim2 == -1) {
		return (LINE_MATCHES_OOB);
	} else if (lim2 > 0 && (value == 0 || value > lim1)) {
		return (ZERO_MATCHES);
	} else if (lim2 == 0) {
		return (NOT_ENGH_MATCHES);
	} else if (lim2 == -1) {
		return (LINE_MATCHES_OOB);
	} else {
		return (PROMPT_OK);
	}
}

static uint_t	set_prompt_value(char const *prompt, int lim1,
		int lim2, void (*(*print_error))())
{
	int	value = 0;
	prompt_error_t	err_sign = 0;

	if (!my_str_isnum(prompt)) {
		print_error[INVALID_PROMPT]();
		return (0);
	} 
	value = my_getnbr(prompt);
	err_sign = check_for_incorrect_input(value, lim1, lim2);
	if (err_sign != PROMPT_OK) {
		print_error[err_sign](lim1);
		return (0);
	}
	if (err_sign == NOT_ENGH_MATCHES) {
		return (-1);
	}
	return (value);
}

static uint_t	get_input(char *msg, int lim1, int lim2,
	void (*(*print_error))())
{
	char	*prompt = NULL;
	int	value = 0;

	while (value == 0) {
		my_putstr_fd(1, msg);
		prompt = get_next_line(0);
		value = set_prompt_value(prompt, lim1, lim2,
			print_error);
		free(prompt);
		prompt = NULL;
	}
	return (value);
}

int	get_line_input(game_board_t *board)
{
	int	value = 0;
	void	(*perr_line_tab[])() = {
		&print_error_line_oor,
		&print_error_invalid_prompt
	};
	void	(*(*accessor))() = perr_line_tab;

	value = get_input("Line: ", board->max_lines, -1, accessor);
	return ((value - 1));
}

int	get_matches_input(game_board_t *board, uint_t line)
{
	int	value = 0;
	void	(*perr_matches_tab[])() = {
		&print_error_matches_oob,
		&print_error_invalid_prompt,
		&print_error_no_matches,
		&print_error_not_enough_matches
	};
	void	(*(*accessor))() = perr_matches_tab;

	value = get_input("Matches: ", board->match_limit,
		board->remmatches_atl[line], accessor);
	return (value);
}
