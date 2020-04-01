/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoares <msoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:31:55 by msoares           #+#    #+#             */
/*   Updated: 2020/03/02 20:09:19 by msoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>

int			get_next_line(int fd, char **line);
char		*ft_strdup(char const *str);
size_t		ft_strlen(char const *str);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(char const *str, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif
