/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thardy <thardy@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:04:50 by thardy            #+#    #+#             */
/*   Updated: 2021/09/16 15:04:50 by thardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *) src;
	d = (char *) dest;
	while (n-- > 0)
		d[n] = s[n];
	return (d);
}
