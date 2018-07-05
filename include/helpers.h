/*
** EPITECH PROJECT, 2018
** helpers.h
** File description:
** Header file for helpers functions prototypes
*/

#ifndef __MATCHSTICK_HELPERS_H__
#define __MATCHSTICK_HELPERS_H__

#include "stypes.h"

char	**ms_free_strtab(char **display, uint_t height, uint_t width);
uint_t	*ms_free_uinttab(uint_t *tab, uint_t size);
int	ms_uinttabcpy(uint_t *dest, uint_t *src, uint_t size);

#endif
