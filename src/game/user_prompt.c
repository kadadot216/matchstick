/*
** EPITECH PROJECT, 2018
** user_prompt.c
** File description:
** Player's prompt related functions
*/

#include <stdlib.h>
#include "types.h"
#include "my.h"

static uint_t	set_prompt_value(char const *prompt, uint_t upper_bound,
		void (*print_error)())
{
	int	value = 0;

	if (!my_str_isnum(prompt)) {
		my_putstr_fd(2, "Error: invalid input (positive number expected)\n");
		return (0);
	} 
	value = my_getnbr(prompt);
	if (value > (int) upper_bound || value <= 0) {
		print_error((int) upper_bound);
		return (0);
	}
	return (value);
}

uint_t	get_input(char *msg, uint_t upper_limit, void (*print_error)())
{
	char	*prompt = NULL;
	uint_t	value = 0;

	while (value == 0) {
		my_putstr_fd(1, msg);
		prompt = get_next_line(0);
		value = set_prompt_value(prompt, upper_limit, print_error);
		free(prompt);
		prompt = NULL;
	}
	return (value);
}
