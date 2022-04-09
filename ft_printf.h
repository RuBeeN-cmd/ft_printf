/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:05:26 by rrollin           #+#    #+#             */
/*   Updated: 2022/04/07 13:30:05 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_treat_char(const char *str, va_list args);
int		ft_treat_type(const char c, va_list args);
int		ft_putaddr_fd(unsigned long long addr, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putunbr_fd(unsigned int n, int fd);
size_t	ft_strlen(const char *s);
int		ft_putnbr_base_fd(unsigned long long nbr, int fd, char *base);
int		ft_is_base_wrong(char *base);
int		ft_nbrlen_base(unsigned long long nbr, char *base);

#endif
