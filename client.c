/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:10:15 by matde-je          #+#    #+#             */
/*   Updated: 2023/06/20 18:41:27 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	char_to_bit(int pid, char *str)
{
	int		digit;
	char	c;

	while (*str)
	{
		digit = 8;
		c = *str++;
		while (digit--)
		{
			if (c >> digit & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(1000);
		}
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3)
		return (0);
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	char_to_bit(ft_atoi(argv[1]), argv[2]);
}

//int sigaction(int signum,struct sigaction *newact,struct sigaction *oldact);
//sigemptyset(&sa.sa_mask) no signal ignored