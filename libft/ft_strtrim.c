/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thardy <thardy@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:03:03 by thardy            #+#    #+#             */
/*   Updated: 2021/09/16 15:03:03 by thardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (s1 == NULL)
		return (NULL);
	else if (set == NULL)
		return ((char *)s1);
	while (ft_memchr(set, s1[i], ft_strlen(set)))
		i++;
	while (ft_memchr(set, s1[j], ft_strlen(set)))
		j--;
	return (ft_substr(s1, i, j - i + 1));
}
