#include <stdlib.h>
#include "types.h"
#include "my.h"

static uint_t	set_prompt_value(char const *prompt, uint_t upper_bound)
{
	int	value = 0;

	if (!my_str_isnum(prompt)) {
		my_putstr("Invalid input, please try again.\n");
		return (0);
	} 
	value = my_getnbr(prompt);
	if (value > (int) upper_bound || value <= 0) {
		my_putstr("Value is out of bounds.\n");
		return (0);
	}
	return (value);
}

uint_t	get_input(char *msg, uint_t upper_limit)
{
	char	*prompt = NULL;
	uint_t	value = 0;

	if (upper_limit == 0) {
		my_putstr("There's no more sticks at this line!\n");
		return (0);
	}
	while (value == 0) {
		my_putstr(msg);
		prompt = get_next_line(0);
		value = set_prompt_value(prompt, upper_limit);
		free(prompt);
		prompt = NULL;
	}
	return (value);
}
