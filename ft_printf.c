/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:41:50 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/11/22 17:22:28 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_str(const char *str, va_list params)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (str[i])
	{
		if (str[i++] == '%')
			print_str(str[i], params, n);
		i++;
	}
	return (n);
}

int	ft_printf(const char *str, ...)
{
	va_list	params;
	int		n;

	if (!str)
		return (0);
	va_start(params, str);
	n = check_str(str, params);
	va_end(params);
	return (n);
}
