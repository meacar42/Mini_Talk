/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meacar <meacar@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:39:40 by meacar            #+#    #+#             */
/*   Updated: 2022/10/16 15:39:49 by meacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdarg.h>
# include<stdlib.h>
# include<unistd.h>

size_t	ft_putchar(char a);
size_t	ft_putstr(char *str);
int		ft_putnbr_base(size_t n, char *base);
int		ft_printf(const char *str, ...);
int		type_control(va_list list, char *c);
size_t	negorpos(int n);
size_t	ft_strlen(const char *s);
#endif
