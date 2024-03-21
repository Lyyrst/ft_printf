/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:41:22 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/11/26 17:12:23 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int	main(void)
{
	//printf ("np = %d", printf ("lib C :%s\n", "hello"));
	//ft_printf("%c", 'q');
	char str[] = "Hello";
	
	printf ("\nn = %d\n", ft_printf("This %p is an address from the heap", &str));
	printf ("\nn = %d", printf("This %p is an address from the heap", &str));
}
