/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:08:36 by matde-je          #+#    #+#             */
/*   Updated: 2023/06/20 19:22:32 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

long int	ft_putnbr(long int n);
int			ftchar(va_list *arg);
int			ftint(va_list *arg);
int			ft_strlen(char *string);
int			arg_check(char *string, int i);
int			func(char *string, va_list *args, int i);
int			ft_printf(const char	*string, ...);
int			ft_atoi(const char *str);

#endif