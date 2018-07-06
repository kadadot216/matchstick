/*
** EPITECH PROJECT, 2018
** update.c
** File description:
** Board update related functions
*/

#include "types.h"

#include "my.h"

void	remove_sticks(uint_t *remsticks, uint_t nbsticks)
{
	*remsticks -= nbsticks;
}

void	remove_from_display(char *display_line, uint_t nbsticks)
{
	uint_t	i = 0;
	uint_t	removed = 0;

	while (display_line[i] == ' ' && display_line[i] != '\0') {
		i++;
	}
	while (removed < nbsticks) {
		display_line[i] = ' ';
		i++;
		removed++;
	}
}

void	print_updated_board(uint_t nbsticks, uint_t line)
{
	my_putstr_fd(1, "Player removed ");
	my_put_nbr_fd(1, nbsticks);
	my_putstr_fd(1, " from line ");
	my_put_nbr_fd(1, line);
	my_putstr_fd(1, "\n");
}

void	update_board_with(game_board_t *b, p_choice_t *c)
{
	remove_sticks(&b->remsticks_atl[c->line], c->nbsticks);
	remove_from_display(b->display[c->line], c->nbsticks);
	print_updated_board(c->nbsticks, c->line);
}
