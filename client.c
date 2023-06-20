/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:10:15 by matde-je          #+#    #+#             */
/*   Updated: 2023/06/20 16:42:08 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	int_to_bit(int str, int pid)
{
	int	control;
	int	counter;

	control = 128;
	counter = 0;
	while (counter < 8)
	{
		if (str < control)
		{
			kill(pid, SIGUSR1);
			usleep(80);
		}
		else
		{
			str -= control;
			kill(pid, SIGUSR2);
			usleep(80);
		}
		counter++;
		control /= 2;
	}
}

void	error(void)
{
	write(1, "Error, invalid Parameters", 25);
	exit(0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc != 3)
		error();
	pid = atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		int_to_bit((int) argv[2][i], pid);
		i++;
	}
	int_to_bit(0, pid);
}
