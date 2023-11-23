/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:40:34 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/11/22 16:59:06 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *n)
{
	(*n)++;
	write (1, &c, 1);
}

void	ft_putstr(char *str, int *n)
{
	int	i;

	i = -1;
	if (!str)
	{
		ft_putstr("(null)", n);
		return ;
	}
	while (str[++i])
		ft_putchar(str[i], n);
}

void	check_unsigned(int n, int *nb)
{
	if (n < 0)
		return ;
	ft_putnbr(n, nb);
}

void	ft_putnbr(int n, int *nb)
{
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, nb);
		ft_putnbr(n % 10, nb);
	}
	else
		ft_putchar(n + 48, nb);
}
