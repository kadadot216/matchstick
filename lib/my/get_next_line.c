#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	my_linelen(char const *src)
{
	int	i = 0;

	while (src[i] != '\0' && src[i] != '\n') {
		i++;
	}
	if (src[i] == '\n')
		i++;
	return (i);
}

char	*my_strncat(char *dest, char *src, int n)
{
	int	i = 0;
	int	j = 0;

	while (dest[i] != '\0')
		i++;
	while (j < n && (src) && src[j] != '\0') {
		dest[i+j] = src[j];
		j++;
	}
	dest[i+j] = '\0';
	return (dest);
}

char	*gnl_realloc(int tlength, int offset, char *buf, char *o_tmp)
{
	char	*tmp = NULL;
	int	i = 0;

	tmp = malloc(sizeof(char) * (offset + tlength + 1));
	while (i < offset + tlength) {
		tmp[i] = '\0';
		i++;
	}
	if (o_tmp) {
		tmp = my_strncat(tmp, o_tmp, tlength);
		free(o_tmp);
		o_tmp = NULL;
	}
	tmp = my_strncat(tmp, buf, offset);
	return (tmp);
}

int	read_buffer(int *fd, char *buffer, int *rstat, int *last)
{
	if (*last == *rstat) {
		*last = 0;
		*rstat = read(*fd, buffer, READ_SIZE);
	}
	return (*rstat);
}

char	*get_next_line(int fd)
{
	static char	buffer[READ_SIZE];
	static int	last = 0;
	static int	rstat = 0;
	int		total = 0;
	int		pos = 0;
	char		*output = NULL;

	while (rstat > 0 || last == 0) {
		if (read_buffer(&fd, buffer, &rstat, &last) < 1) {
			last = 0;
			return (NULL);
		}
		pos = my_linelen(&buffer[last]);
		output = gnl_realloc(total, pos, &buffer[last], output);
		last += pos;
		total += pos;
		if (output[total-1] == '\n') {
			output[total-1] = '\0';
			return (output);
		}
	}
	return (NULL);
}
