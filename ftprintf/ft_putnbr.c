/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:26:11 by mbouderr          #+#    #+#             */
/*   Updated: 2022/11/11 21:39:56 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long i)
{
	int	count;

	count = 0;
	if (i < 0)
	{
		i *= -1;
		count += ft_putchar('-');
	}
	if (i > 9)
	{
		count += ft_putnbr(i / 10);
		count += ft_putnbr(i % 10);
	}
	if (i >= 0 && i <= 9)
	{
		count += ft_putchar(i + 48);
	}
	return (count);
}
