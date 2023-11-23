/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:24:16 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/11/23 16:14:10 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p(unsigned long long n, int *nb)
{
	if (!n)
	{
		ft_putstr("(nil)", nb);
		return ;
	}
	ft_putstr("0x", nb);
	print_lowerx(n, nb);
}

void	print_lowerx(unsigned long long n, int *nb)
{
	char	*str;

	str = ft_itoa(n);
	ft_putstr(ft_convert_base(str, "0123456789", "0123456789abcdef"), nb);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void	print_upperx(int n, int *nb)
{
	char	*str;
	int		i;

	str = ft_itoa(n);
	str = ft_convert_base(str, "0123456789", "0123456789abcdef");
	i = -1;
	while (str[++i])
		str [i] = ft_toupper(str[i]);
	ft_putstr(str, nb);
}
