/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thardy <thardy@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:03:39 by thardy            #+#    #+#             */
/*   Updated: 2021/09/16 15:03:39 by thardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
