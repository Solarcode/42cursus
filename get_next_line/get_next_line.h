/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thardy <thardy@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:44:05 by thardy            #+#    #+#             */
/*   Updated: 2022/02/14 10:24:14 by thardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_strjoin_mod(char const *s1, char const *s2);
char	*ft_strchr_mod(const char *str, int c);
char	*get_next_line(int fd);
char	*get_line(char *remainder);
char	*new_remainder(char *remainder);
char	*fill_remainder(int fd, char *remainder);

#endif