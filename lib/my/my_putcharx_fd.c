#include <unistd.h>

void	my_putcharx_fd(int fd, char c, int times)
{
	int	i = 0;

	while (i < times) {
		write(fd, &c, 1);
		i++;
	}
}
