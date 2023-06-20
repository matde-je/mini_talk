/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:19:54 by matde-je          #+#    #+#             */
/*   Updated: 2023/06/20 17:35:44 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "mini_talk.h"

void	put_char_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	put_str_fd(char *s, int fd)
{
	int	i;

	if (s[0] != "\0")
	{
		i = 0;
		while (s[i])
		{
			put_char_fd(s[i], fd);
			i++;
		}
	}
}

void	put_nbr_fd(int nbr, int fd)
{
	int	res;

	if (nbr < 0)
	{
		put_char_fd('-', fd);
		if (nbr == -2147483648)
		{
			put_char_fd('2', fd);
			nbr = -147483648;
		}
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		put_nbr_fd(nbr / 10, fd);
		put_nbr_fd(nbr % 10, fd);
	}
	if (nbr <= 9)
	{
		res = nbr + 48;
		put_char_fd(res, fd);
	}
}

/*int main()
{
	int fd4;
	char s[] = "ola";

	fd4 = open("fd4.txt", O_RDWR);
	put_str_fd(s, fd4);
}*/