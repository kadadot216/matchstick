/*
** EPITECH PROJECT, 2018
** game_messages.c
** File description:
** Function for related game messages
*/

#include "stypes.h"
#include "my.h"

void	print_loss_msg(game_status_t status)
{
	if (status == PLAYER_WON) {
		my_putstr_fd(1, "I lost... snif... but"
			"I'll get you next time!!\n");
	} else if (status == AI_WON) {
		my_putstr_fd(1, "You lost, too bad...\n");
	}
}

void	print_updated_board(uint_t matches, uint_t line, turn_type_t type)
{
	if (type == PLAYER) {
		my_putstr_fd(1, "Player");
	} else if (type == AI) {
		my_putstr_fd(1, "AI");
	}
	my_putstr_fd(1, " removed ");
	my_put_nbr_fd(1, matches);
	my_putstr_fd(1, " from line ");
	my_put_nbr_fd(1, line);
	my_putstr_fd(1, "\n");
}

