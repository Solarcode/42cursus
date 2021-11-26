/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thardy <thardy@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:03:18 by thardy            #+#    #+#             */
/*   Updated: 2021/09/16 15:03:18 by thardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (str1[i] < str2[i])
			return (-1);
		if (str1[i] > str2[i])
			return (1);
		if (str1[i] == 0 && str2[i])
			return (-1);
		if (str2[i] == 0 && str1[i])
			return (1);
		i++;
	}
	return (0);
}
