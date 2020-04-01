/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoares <msoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:32:15 by msoares           #+#    #+#             */
/*   Updated: 2020/03/02 19:53:30 by msoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(char const *str)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0')
	{
		i += 1;
	}
	return (i);
}

char		*ft_strdup(char const *str)
{
	size_t	len;
	char	*dest;

	len = 0;
	while (str[len] != '\0')
		len++;
	dest = (char *)malloc(len + 1 * sizeof(*str));
	if (!dest)
	{
		return (0);
	}
	len = 0;
	while (str[len])
	{
		dest[len] = str[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*res;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((str = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	res = str;
	while (*s1)
	{
		*str = *s1;
		str++;
		s1++;
	}
	while (*s2)
	{
		*str = *s2;
		str++;
		s2++;
	}
	*str = '\0';
	return (res);
}

char		*ft_strchr(char const *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
		{
			return ((char *)str);
		}
		++str;
	}
	if ((char)c == '\0')
	{
		return ((char *)str);
	}
	return (0);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*substr;

	if (!s)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	if (!(substr = malloc((len + 1) * sizeof(*substr))))
		return (NULL);
	while ((i < len) && (start + i) < slen)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
