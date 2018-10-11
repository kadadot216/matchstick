#include <stdlib.h>
#include "stypes.h"
#include "my.h"

char	**ms_free_strtab(char **display, uint_t height, uint_t width)
{
	uint_t	j = 0;

	while (j < height) {
		my_memset(display[j], '\0', width);
		free(display[j]);
		display[j] = NULL;
		j++;
	}
	free(display);
	display = NULL;
	return (display);
}
