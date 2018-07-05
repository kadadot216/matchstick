/*
** EPITECH PROJECT, 2018
** ms_uinttabcpy.c
** File description:
** Copy an already mallocd uinttab into another
*/

#include <stdlib.h>
#include "stypes.h"

int	ms_uinttabcpy(uint_t *dest, uint_t *src, uint_t size)
{
	uint_t	i = 0;

	if (dest == NULL || src == NULL) {
		return (-1);
	}
	while (i < size) {
		dest[i] = src[i];
		i++;
	}
	return (0);
}
