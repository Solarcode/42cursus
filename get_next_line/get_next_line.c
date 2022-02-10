/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thardy <thardy@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:43:06 by thardy            #+#    #+#             */
/*   Updated: 2022/02/10 11:50:45 by thardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			read_bytes;

	line = 0;
	read_bytes = 1;
	while (!ft_strchr(buf, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes > 0)
			buf[read_bytes] = 0;
				printf("buf = %s\n", buf);
		line = get_line(buf, line);
				printf("line: %s", line);
	}
	return (line);
}

int	main(void)
{
    FILE	*fp;
    int		fd;
	int		iter;

	iter = 0;
    fp = fopen("lorem-ipsum.txt", "r");
	fd = fileno(fp);
    printf("fd: %d\n\n", fd);
	while (iter < 8)
    {
		if (printf("%i %s\n", iter, get_next_line(fd)) == 1)
			break;
		iter++;
	}
}
