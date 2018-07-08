/*
** EPITECH PROJECT, 2018
** messages.h
** File description:
** Header file for game_messages.c
*/

#ifndef __MATCHSTICK_MESSAGES_H__
#define __MATCHSTICK_MESSAGES_H__

#include "stypes.h"

void	print_loss_msg(game_status_t status);
void	print_updated_board(uint_t matches, uint_t line, turn_type_t type);

#endif
