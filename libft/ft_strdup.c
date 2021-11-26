/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thardy <thardy@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:03:57 by thardy            #+#    #+#             */
/*   Updated: 2021/09/16 15:03:57 by thardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ret;

	ret = (char *) malloc(ft_strlen(str) + 1);
	ft_strlcpy(ret, str, ft_strlen(str) + 1);
	return (ret);
}
