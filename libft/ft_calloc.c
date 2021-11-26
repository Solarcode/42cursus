/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thardy <thardy@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:04:43 by thardy            #+#    #+#             */
/*   Updated: 2021/11/18 13:36:47 by thardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*p;
	size_t	bytes;

	if (nitems == 0 || size == 0)
	{
		nitems = 1;
		size = 1;
	}
	bytes = nitems * size;
	p = malloc(bytes);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, bytes);
	return (p);
}
