#include <unistd.h>

void	my_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
}
