/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 02:58:48 by mbouderr          #+#    #+#             */
/*   Updated: 2022/10/28 04:07:34 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *first, char const *last)
{
	char	*s1;
	char	*s2;
	size_t	i;
	char	*p;

	s1 = (char *)first;
	s2 = (char *)last;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	p = (char *)ft_calloc(((ft_strlen(s1) + ft_strlen(s2)) + 1), sizeof(char));
	if (p == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		p[i] = s1[i];
		i++;
	}
	i = 0;
	while (i <= ft_strlen(s2))
	{
		p[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	return (p);
}
