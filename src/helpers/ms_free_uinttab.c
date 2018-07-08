#include <stdlib.h>
#include "stypes.h"

uint_t	*ms_free_uinttab(uint_t *tab, uint_t size)
{
	uint_t	i = 0;

	while (i < size) {
		tab[i] = 0;
		i++;
	}
	free(tab);
	tab = NULL;
	return (tab);
}
