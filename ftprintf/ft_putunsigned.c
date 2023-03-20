/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:26:16 by mbouderr          #+#    #+#             */
/*   Updated: 2022/11/11 22:47:20 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int i)
{
	int	count;

	count = 0;
	if (i > 9)
	{
		count += ft_putunsigned(i / 10);
		count += ft_putunsigned(i % 10);
	}
	if (i >= 0 && i <= 9)
		count += ft_putchar(i + 48);
	return (count);
}
