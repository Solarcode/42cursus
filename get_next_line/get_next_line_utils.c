/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thardy <thardy@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:59:48 by thardy            #+#    #+#             */
/*   Updated: 2022/02/11 15:45:15 by thardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (c > 127)
		return ((char *)str);
	if (c == 0)
		return ((char *)str + ft_strlen(str));
	while (str[i] != 0)
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	if (s1)
		while (s1[j])
			ret[i++] = s1[j++];
	j = 0;
	while (s2[j])
		ret[i++] = s2[j++];
	ret[i] = 0;
	free((void *)s1);
	return (ret);
}
