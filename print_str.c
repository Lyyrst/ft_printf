/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:56:49 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/11/22 18:02:05 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(char c, va_list params, int n)
{
	if (c == 'c')
		ft_putchar(va_arg(params, int));
	if (c == 's')
		ft_putstr(va_arg(params, char *));
	//if (c == 'p')
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(params, int));
	if (c == 'u')
		check_unsigned(va_arg(params, unsigned int));
	if (c == 'x')
		print_lowerx(va_arg(params, int));
	if (c == 'X')
		print_upperx(va_arg(params, int));
	if (c == '%')
		ft_putchar('%');
	n++;
}
