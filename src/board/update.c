/*
** EPITECH PROJECT, 2018
** update.c
** File description:
** Board update related functions
*/

#include "types.h"

#include "my.h"

void	remove_sticks(uint_t *remmatches, int *matches)
{
	if ((uint_t) *matches > *remmatches) {
		*matches = *remmatches;
	} 
	*remmatches -= *matches;
}

void	remove_from_display(char *display_line, uint_t matches)
{
	uint_t	i = 0;
	uint_t	removed = 0;

	while (display_line[i] == ' ' && display_line[i] != '\0') {
		i++;
	}
	while (removed < matches) {
		display_line[i] = ' ';
		i++;
		removed++;
	}
}

void	print_updated_board(uint_t matches, uint_t line)
{
	my_putstr_fd(1, "Player removed ");
	my_put_nbr_fd(1, matches);
	my_putstr_fd(1, " from line ");
	my_put_nbr_fd(1, line);
	my_putstr_fd(1, "\n");
}

void	update_board_with(game_board_t *b, p_choice_t *c)
{
	remove_sticks(&b->remmatches_atl[c->line], &c->matches);
	remove_from_display(b->display[c->line], c->matches);
	print_updated_board(c->matches, c->line);
}
