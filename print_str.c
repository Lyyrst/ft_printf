/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:56:49 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/11/23 16:11:45 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(char c, va_list params, int *n)
{
	if (c == 'c')
		ft_putchar(va_arg(params, int), n);
	if (c == 's')
		ft_putstr(va_arg(params, char *), n);
	if (c == 'p')
		print_p(va_arg(params, unsigned long long), n);
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(params, int), n);
	if (c == 'u')
		check_unsigned(va_arg(params, unsigned int), n);
	if (c == 'x')
		print_lowerx(va_arg(params, int), n);
	if (c == 'X')
		print_upperx(va_arg(params, int), n);
	if (c == '%')
		ft_putchar('%', n);
}
