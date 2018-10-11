#include <stdlib.h>

int	random_iv(int min, int max)
{
	int	diff = ((max + 1) - min);

	return (min + (random() % diff));
}
