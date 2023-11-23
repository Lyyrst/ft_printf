/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:41:22 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/11/23 15:16:31 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int	main(void)
{
	//printf ("np = %d", printf ("lib C :%s\n", "hello"));
	//ft_printf("%c", 'q');
	printf ("\nn = %d\n", ft_printf("%p", -1));
	printf ("\nn = %d", printf("%p", -1));
}
