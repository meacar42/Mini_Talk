/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meacar <meacar@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:40:13 by meacar            #+#    #+#             */
/*   Updated: 2022/10/17 13:56:08 by meacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_putchar(char a)
{
	write(1, &a, 1);
	return (1);
}

size_t	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (i < ft_strlen(str))
		ft_putchar(str[i++]);
	return (i);
}

int	ft_putnbr_base(size_t n, char *base)
{
	size_t		base_len;
	static int	counter;

	counter = 1;
	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		ft_putnbr_base(n / base_len, base);
		counter++;
	}
	ft_putchar(base[n % base_len]);
	return (counter);
}
