#include "gnl_simplified.h"
#include <unistd.h>
#include "my.h"

int	ask_number(void)
{
	char	buff[SIZE_READ];
	char	res[512];
	int	n;
	int	i = 0;

	while ((n = read(0, buff, SIZE_READ)) > 0 &&
		buff[0] != '\n' && i < 512) {
		res[i++] = buff[0];
	}
	res[i] = 0;
	if (my_strlen(res) == 0 && n <= 0) {
		return (READ_ERROR);
	}
	if ((my_str_isnum(res) == 0) || ((n = my_getnbr(res)) < 0)) {
		return (-1);
	}
	return (n);
}
