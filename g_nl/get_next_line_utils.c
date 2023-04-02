/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:35:18 by mbouderr          #+#    #+#             */
/*   Updated: 2023/03/29 23:07:56 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_callocget(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	while (i < (count * size))
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

size_t	ft_strlenget(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoinget(char *s1, char *s2)
{
	size_t	i;
	char	*p;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlenget(s1);
	len_s2 = ft_strlenget(s2);
	i = 0;
	p = (char *)ft_callocget(((len_s1 + len_s2) + 1), sizeof(char));
	if (p == NULL)
		return (NULL);
	while (i < len_s1)
	{
		p[i] = s1[i];
		i++;
	}
	i = 0;
	while (i <= len_s2)
	{
		p[i + len_s1] = s2[i];
		i++;
	}
	free(s1);
	return (p);
}

ssize_t	ft_strchrget(char *s, int c)
// if 'c is available return (i) else return (-1)
{
	int	len;
	int	i;

	len = ft_strlenget(s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*ft_substrget(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && i < len + start)
	{
		str[j++] = s[i++];
	}
	str[j] = '\0';
	return (str);
}
