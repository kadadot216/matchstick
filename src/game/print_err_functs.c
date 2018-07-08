#include "my.h"

void	print_error_line_oor(void)
{
	my_putstr_fd(2, "Error: this line is out of range\n");
}

void	print_error_invalid_prompt(void)
{
	my_putstr_fd(2, "Error: invalid input (positive number expected)\n");
}

void	print_error_matches_oob(int upper_bound)
{
	my_putstr_fd(2, "Error: you cannot remove more than ");
	my_put_nbr_fd(2, upper_bound);
	my_putstr_fd(2, " matches per turn\n");
}

void	print_error_no_matches(void)
{
	my_putstr_fd(2, "Error: you have to remove at least one match\n");
}

void	print_error_not_enough_matches(void)
{
	my_putstr_fd(2, "Error: not enough matches on this line\n");
}
