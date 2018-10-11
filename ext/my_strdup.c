#include <stdlib.h>
#include "my.h"

char	*my_strdup(char const *src)
{
	int	i = 0;
	int	slen = my_strlen(src);
	char	*copy;

	copy = malloc(sizeof(*src) * (slen + 1));
	my_memset(copy, '\0', slen);
	while (src[i] != '\0') {
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
