/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 02:37:28 by mbouderr          #+#    #+#             */
/*   Updated: 2022/10/27 02:37:30 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	const unsigned char	*s;
	unsigned char		*d;

	i = len;
	s = src;
	d = dst;
	if (s == NULL && d == NULL)
		return (d);
	if (s > d)
		ft_memcpy(d, s, len);
	if (s < d)
	{
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	return (d);
}
