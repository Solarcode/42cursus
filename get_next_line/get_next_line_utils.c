/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thardy <thardy@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:59:48 by thardy            #+#    #+#             */
/*   Updated: 2022/01/18 12:56:45 by thardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	if (!dst || !src)
		return (0);
	while (src[c])
		c++;
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	if (size)
		dst[i] = 0;
	return (c);
}

char	*strdup_free(char *str)
{
	char	*ret;

	ret = (char *) malloc(ft_strlen(str) + BUFFER_SIZE + 1);
	ft_strlcpy(ret, str, ft_strlen(str) + 1);
	free(str);
	return (ret);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*c;

	i = 0;
	c = (char *) s;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*p;
	size_t	bytes;

	if (nitems == 0 || size == 0)
	{
		nitems = 1;
		size = 1;
	}
	bytes = nitems * size;
	p = malloc(bytes);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, bytes);
	return (p);
}
