/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thardy <thardy@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:44:05 by thardy            #+#    #+#             */
/*   Updated: 2022/02/10 11:49:59 by thardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
// # define BUFFER_SIZE 42 // remove for testing & submission

// remove these
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
// remove these

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	line_cat(char *line, char *buf, int i);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nitems, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int	    findchar(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
char    *get_line(char *buf, char *line);

#endif