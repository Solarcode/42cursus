/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thardy <thardy@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:43:06 by thardy            #+#    #+#             */
/*   Updated: 2022/02/14 10:27:27 by thardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_remainder(int fd, char *remainder)
{
	char	*buf;
	int		read_bytes;

	read_bytes = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_strchr_mod(remainder, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = 0;
		remainder = ft_strjoin_mod(remainder, buf);
	}
	free(buf);
	return (remainder);
}

char	*get_line(char *remainder)
{
	int		i;
	char	*str;

	i = 0;
	if (!remainder[i])
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	str = malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
	{
		str[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
	{
		str[i] = remainder[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*new_remainder(char *remainder)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	str = malloc(ft_strlen(remainder) - i + 1);
	if (!str)
		return (NULL);
	i++;
	while (remainder[i])
		str[j++] = remainder[i++];
	str[j] = 0;
	free(remainder);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	remainder = fill_remainder(fd, remainder);
	if (!remainder)
		return (NULL);
	line = get_line(remainder);
	remainder = new_remainder(remainder);
	return (line);
}
