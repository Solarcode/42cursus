/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thardy <thardy@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:04:02 by thardy            #+#    #+#             */
/*   Updated: 2021/09/16 15:04:02 by thardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
