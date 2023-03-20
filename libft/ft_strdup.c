/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 02:53:32 by mbouderr          #+#    #+#             */
/*   Updated: 2022/10/27 22:03:33 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = ft_calloc(ft_strlen((char *)s1) + 1, sizeof(char));
	if (!str)
	{
		return (NULL);
	}
	ft_memmove(str, s1, ft_strlen((char *)s1) + 1);
	return (str);
}
