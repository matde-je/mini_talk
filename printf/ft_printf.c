/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:10:27 by matde-je          #+#    #+#             */
/*   Updated: 2022/11/22 16:00:00 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		count;
	va_list	arg;
	int		total;

	count = -1;
	total = 0;
	va_start(arg, s);
	while (++count < ft_strlen((char *)s))
	{
		if (arg_check((char *)s, count) == 1)
		{
			write(1, "%", 1);
			total += 1;
		}
		if (arg_check((char *)s, count) == 2)
		{
			write(1, &s[count], 1);
			total += 1;
		}
		else
			total += func((char *)s, &arg, count++);
	}
	va_end(arg);
	return (total);
}
