/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:59:55 by rrollin           #+#    #+#             */
/*   Updated: 2022/04/07 20:59:44 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_nbrlen_base(unsigned long long nbr, char *base)
{
	int	len;

	len = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		nbr /= ft_strlen(base);
		len++;
	}
	return (len);
}

int	ft_is_base_wrong(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (1);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			else
				j++;
		}
		i++;
	}
	return (0);
}

int	ft_putnbr_base_fd(unsigned long long nbr, int fd, char *base)
{
	int	len;

	len = ft_nbrlen_base(nbr, base);
	if (ft_is_base_wrong(base))
		return (0);
	if (nbr / ft_strlen(base))
	{
		ft_putnbr_base_fd(nbr / ft_strlen(base), fd, base);
	}
	ft_putchar_fd(base[nbr % ft_strlen(base)], fd);
	return (len);
}

int	ft_putaddr_fd(unsigned long long addr, int fd)
{
	if (addr == 0)
		return (ft_putstr_fd("(nil)", fd));
	ft_putstr_fd("0x", 1);
	return (ft_putnbr_base_fd(addr, fd, "0123456789abcdef") + 2);
}
