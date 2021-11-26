/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thardy <thardy@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:03:10 by thardy            #+#    #+#             */
/*   Updated: 2021/09/16 15:03:10 by thardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s2 || !*s2)
		return ((char *)s1);
	while (i < n && s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j] && i + j < n && s2[j])
		{
			j++;
			if (!(s2[j]))
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
