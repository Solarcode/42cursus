/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thardy <thardy@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:43:06 by thardy            #+#    #+#             */
/*   Updated: 2022/01/18 14:40:43 by thardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	int			i;
	char 		*buf;
	char		*tmp;
	
	i = 0;
    buf = malloc(BUFFER_SIZE + 1);
    if (!buf)
        return (0);
	while (i < BUFFER_SIZE)
	{
    	read(fd, buf + i, 1);
		if (buf[i] == '\n' || i + 1 == BUFFER_SIZE)
		{
			if (!str)
			{
				str = malloc(BUFFER_SIZE + 1);
				ft_strlcpy(str, buf, ft_strlen(buf));
			}
			else
			{
				tmp = str;
				str = malloc(ft_strlen(tmp) + i + 1);
				str[ft_strlen(tmp) + i] = 0;
				ft_strlcpy(str, tmp, ft_strlen(tmp));
				ft_strlcpy(str + ft_strlen(tmp) + 1, buf, ft_strlen(buf));
				free(tmp);
				printf("str = %s\n", str);
			}
			if (str[ft_strlen(str)] == '\n')
					return (str);
		}
		i++;
		// printf("i = %i, buf = %s\n", i, buf);			  // TESTING
	}
    return (0);
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
	while (iter < 1)
    {
		printf("GNL RETURN: %s", get_next_line(fd));
		printf("\n\n\n");
		iter++;
	}
}