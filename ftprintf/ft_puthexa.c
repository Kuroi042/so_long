/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:26:08 by mbouderr          #+#    #+#             */
/*   Updated: 2022/11/11 21:40:07 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int i, char c)
{
	char	*min;
	char	*maj;

	min = "0123456789abcdef";
	maj = "0123456789ABCDEF";
	if (c == 'x')
	{
		write(1, &min[i], 1);
		return (1);
	}
	if (c == 'X')
	{
		write(1, &maj[i], 1);
		return (1);
	}
	return (0);
}

int	ft_puthex(unsigned int i, char c)
{
	int	count;

	count = 0;
	if (i >= 16)
	{
		count += ft_puthex(i / 16, c);
		count += ft_puthex(i % 16, c);
	}
	else if (i >= 0 && i <= 15)
		count += ft_hex(i, c);
	return (count);
}
