/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:22:13 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/03/28 12:57:07 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs_putnbr(int number)
{
	if (number < 0)
		return (number * -1);
	return (number);
}

static void	ft_write_digit(int n, int fd)
{
	char	digit;

	if (n / 10 != 0)
		ft_write_digit(n / 10, fd);
	digit = ft_abs_putnbr(n % 10) + '0';
	write(fd, &digit, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	ft_write_digit(n, fd);
}
