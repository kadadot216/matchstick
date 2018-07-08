#include "types.h"
#include "error_fcts.h"

void	check_for_invalid_prompt(int *value)
{
	if (*value < 0) {
		print_error_invalid_prompt();
	}
}

int	line_is_valid(int value, uint_t max_lines)
{
	check_for_invalid_prompt(&value);
	if (value > 0 && value > ((int) max_lines)) {
		print_error_line_oor();
		return (0);
	}
	return (value);
}

int	matches_are_valid(int value, uint_t remmatches, uint_t limit)
{
	check_for_invalid_prompt(&value);
	if (value == 0) {
		print_error_no_matches();
		return (0);
	} else if (remmatches == 0) {
		print_error_not_enough_matches();
		return (-1);
	} else if (value > ((int) limit)) {
		print_error_matches_oob(limit);
		return (0);
	}
	return (value);
}
