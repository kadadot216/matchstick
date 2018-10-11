#include "my.h"

int	my_put_nbr_fd(int fd, int nb)
{
	if (nb < 0) {
		my_putchar_fd(fd, '-');
		nb = -nb;
	}
	if (nb / 10)
		my_put_nbr_fd(fd, nb / 10);
	my_putchar_fd(fd, (nb % 10 + '0'));
	return (0);
}

