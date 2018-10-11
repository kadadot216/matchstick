int	my_char_isalpha(char const c)
{
	if ((c >= 'a' && c <= 'z') ||
		(c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	my_str_isalpha(char const *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (!my_char_isalpha(str[i]))
			return (0);
		else
			i++;
	}
	return (1);
}
