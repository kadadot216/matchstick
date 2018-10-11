#include <unistd.h>

int	my_putstr_fd(int fd, const char *str)
{
	int	i = 0;

	while (str[i] != '\0')
		i++;
	write(fd, str, i);
	i = 0;
	return (0);
}
