/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** Displays, one-by-one, the characters of a string
*/

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
