/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:04:50 by rrollin           #+#    #+#             */
/*   Updated: 2022/04/02 16:14:06 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	int		len;

	nbr = n;
	len = 0;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		len++;
		nbr = -nbr;
	}
	if (nbr / 10)
		len += ft_putnbr_fd(nbr / 10, fd);
	return (ft_putchar_fd(nbr % 10 + '0', fd) + len);
}
