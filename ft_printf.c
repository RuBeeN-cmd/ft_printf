/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:23:32 by rrollin           #+#    #+#             */
/*   Updated: 2022/04/05 16:15:07 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_treat_type(const char c, va_list args)
{
	char	*base;

	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (c == 'p')
		return (ft_putaddr_fd(va_arg(args, unsigned long long), 1));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_putunbr_fd(va_arg(args, unsigned int), 1));
	else if (c == 'x')
	{
		base = "0123456789abcdef";
		return (ft_putnbr_base_fd(va_arg(args, unsigned int), 1, base));
	}
	else if (c == 'X')
	{
		base = "0123456789ABCDEF";
		return (ft_putnbr_base_fd(va_arg(args, unsigned int), 1, base));
	}
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_treat_char(const char *str, va_list args)
{
	int	nb_char;
	int	i;

	nb_char = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i++], 1);
			nb_char++;
		}
		else
		{
			nb_char += ft_treat_type(str[i + 1], args);
			i += 2;
		}
	}
	return (nb_char);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		nb_char;

	if (!str)
		return (-1);
	va_start(args, str);
	nb_char = ft_treat_char(str, args);
	va_end(args);
	return (nb_char);
}
