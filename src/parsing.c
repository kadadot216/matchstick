#include <stdlib.h>
#include "defs.h"
#include "my.h"

int	parse_value(char *arg)
{
	int	value = -1;

	if (arg == NULL || arg[0] == '\0' || !my_str_isnum(arg)) {
		return (-1);
	} else {
		value = my_getnbr(arg);
	}
	return (value);
}
