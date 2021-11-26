/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thardy <thardy@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:02:52 by thardy            #+#    #+#             */
/*   Updated: 2021/09/16 15:02:53 by thardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
