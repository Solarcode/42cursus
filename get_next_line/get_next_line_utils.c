/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thardy <thardy@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:59:48 by thardy            #+#    #+#             */
/*   Updated: 2022/02/10 11:49:51 by thardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *buf, char *line)
{
	int	i;

	i = 0;
	while (buf[i] && buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (line)
		return(ft_strjoin(line, buf));
	else
		return(line = ft_substr(buf, 0, i));
	// printf("line after substr assign: %s\n\n\n", line);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (c > 127)
		return ((char *)str);
	while (str[i] || (str[i] == 0 && c == 0))
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (start > ft_strlen(s))
		s2 = malloc(1);
	else if (len > ft_strlen(s + start))
		s2 = malloc(ft_strlen(s + start) + 1);
	else
		s2 = malloc(len + 1);
	if (!s2)
		return (NULL);
	if (start < ft_strlen(s))
		while (s[start] && i < len)
			s2[i++] = s[start++];
	s2[i] = 0;
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	while (s1[j])
		ret[i++] = s1[j++];
	j = 0;
	while (s2[j])
		ret[i++] = s2[j++];
	ret[i] = 0;
	return (ret);
}

int	findchar(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (c > 127)
		return (-1);
	while (str[i] || (str[i] == 0 && c == 0))
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (ft_strlen(str));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*og_dst;
	const char	*og_src;
	size_t		n;
	size_t		len;

	og_dst = dst;
	og_src = src;
	n = size;
	while (n-- && *dst)
		dst++;
	len = dst - og_dst;
	n = size - len;
	if (n-- == 0)
		return (len + ft_strlen(src));
	while (*src)
	{
		if (n)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = 0;
	return (len + (src - og_src));
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

void	line_cat(char *line, char *buf, int i)
{
	char	*tmp;

	tmp = ft_strjoin(line, ft_substr(buf, 0, i));
	free(line);
	line = tmp;
}
