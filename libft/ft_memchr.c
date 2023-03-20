/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 02:31:45 by mbouderr          #+#    #+#             */
/*   Updated: 2022/10/27 02:32:08 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	ch;

	ch = (unsigned char)c;
	s = (unsigned char *)src;
	if (!n)
		return (0);
	while (*s != ch && --n)
		s++;
	if (*s == ch)
		return (s);
	return (NULL);
}
