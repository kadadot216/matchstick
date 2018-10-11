#include <stdlib.h>
#include "./include/ext.h"
#include "parsing.h"

int	set_random_difficulty(void)
{
	invalid_diff_info();
	return (random_iv(0, 1));
}

int	set_difficulty_lvl(char *setting)
{
	if (!my_strcmp(setting, "easy")) {
		return (0);
	} else if (!my_strcmp(setting, "hard")) {
		return (1);
	} else {
		return (set_random_difficulty());
	}
}

int	parse_difficulty(char *arg)
{
	char	*setting = NULL;
	int	difficulty = 0;

	if (arg == NULL || arg[0] == '\0' || !my_str_isalpha(arg)) {
		return (set_random_difficulty());
	}
	setting = my_strdup(arg);
	setting = my_strlowcase(setting);
	difficulty = set_difficulty_lvl(setting);
	free(setting);
	return (difficulty);
}
