/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:04:24 by mbouderr          #+#    #+#             */
/*   Updated: 2022/11/11 21:39:53 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstring(char *str);
int	ft_putnbr(long n);
int	ft_putunsigned(unsigned int i);
int	ft_puthex(unsigned int i, char c);
int	ft_adress(void *n);
int	ft_printf(const char *str, ...);

#endif
