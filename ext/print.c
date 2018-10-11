#include "my.h"

void	ext_print_help_msg(char *pname)
{
	my_putstr_fd(1, "Usage:\n");
	my_putstr_fd(1, pname);
	my_putstr_fd(1, " <total number of line> <matchsticks limit>"
		" <ai_setting: EASY - HARD>\n");
}

void	ext_print_seldiff(int ai_lvl)
{
	char	*diff_msg[5] = {"EASY", "HARD"};

	my_putstr_fd(1, "Difficulty set to: ");
	my_putstr_fd(1, diff_msg[ai_lvl]);
	my_putchar_fd(1, '\n');
}

void	invalid_diff_info(void)
{
	my_putstr_fd(1, "Invalid or no difficulty mentionned.\n"
		"Setting up random difficulty...\n");
}
