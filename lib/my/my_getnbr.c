/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** Returns a string as a number
*/

#include "my.h"

int	my_getnbr(char const *str)
{
	int	sum;
	char	sign;

	sum = 0;
	while (*str == '-' || *str == '+') {
		sign = *str;
		str++;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9') {
		if (sum > 214748364)
			return (0);
		if (sign == '+' && sum == 214748364 && *str > 7)
			return (0);
		if (sign == '-' && sum == 214748364 && *str > 8)
			return (0);
		sum = (sum * 10 + (*str - '0'));
		str++;
	}
	return ((sign == '-' ? (- sum) : (sum)));
}
