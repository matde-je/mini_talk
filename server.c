/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:10:21 by matde-je          #+#    #+#             */
/*   Updated: 2023/06/20 18:44:43 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	handler(int signal)
{
	static int	str = 0;
	static int	get_char = 0;

	if (signal == SIGUSR1)
		str = (str << 1) | 1;
	else
		str = str << 1;
	if (++get_char == 8)
	{
		get_char = 0;
		ft_printf("%c", (char)str);
		str = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("pid = %d\n", getpid());
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
