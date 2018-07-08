/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** Header file for my lib
*/

#ifndef __MY_H__
#define __MY_H__

void	my_putchar_fd(int fd, char c);
void	my_putcharx_fd(int fd, char c, int times);
void	my_putstr_fd(int fd, char *str);
void	my_putstrtab(char **tab);
int	my_strtablen(char **tab);
char	*my_strdup(char const *src);
char	**my_strtabdup(char **tab);
int	my_strlen(char const *str);
void	my_memset(char *str, char c, unsigned int size);
int	my_str_isnum(char const *str);
int	my_char_isnum(char const c);
int	my_getnbr(char const *stc);
int	my_strlen(char const *str);
int	my_put_nbr_fd(int fd, int nb);
char	*get_next_line(int fd);

#endif
