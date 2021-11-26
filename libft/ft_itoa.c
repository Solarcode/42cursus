/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thardy <thardy@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:05:12 by thardy            #+#    #+#             */
/*   Updated: 2021/09/16 15:05:12 by thardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reverse(char *s, int len)
{
	int		i;
	char	c;

	i = 0;
	while (i < len)
	{
		c = s[len];
		s[len--] = s[i];
		s[i] = c;
		i++;
	}
}

static int	digits(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	fill_str(char *s, int n)
{
	int	i;

	i = 0;
	while (n > 9)
	{
		s[i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	s[i] = n + 48;
}

char	*ft_itoa(int n)
{
	int		sign;
	int		len;
	char	*s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	len = (digits(n) + sign);
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[len] = 0;
	if (sign)
		s[len - 1] = '-';
	fill_str(s, n);
	reverse(s, len - 1);
	return (s);
}
