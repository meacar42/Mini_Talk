/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meacar <meacar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:53:43 by meacar            #+#    #+#             */
/*   Updated: 2022/12/05 10:37:24 by meacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return (num);
}

void	send_string(int pid, char *str)
{
	int				i;
	unsigned char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if ((c >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
}

int	main(int ac, char **argv)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(argv[1]);
		send_string(pid, argv[2]);
	}
	else
		ft_printf("Error \n");
}
