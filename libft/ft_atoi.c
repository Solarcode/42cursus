/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thardy <thardy@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:02:23 by thardy            #+#    #+#             */
/*   Updated: 2021/09/16 15:02:23 by thardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12
		|| c == 13)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	ret;
	int			sign;
	int			i;

	sign = 1;
	i = 0;
	ret = 0;
	while (ft_isspace(str[i]) && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		ret = ret * 10 + (str[i] - 48);
		i++;
	}
	ret *= sign;
	return (ret);
}
