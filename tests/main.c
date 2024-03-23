/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:14:48 by rgrochow          #+#    #+#             */
/*   Updated: 2024/03/20 18:14:54 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

void run_libc_tests(void)
{
	ft_memset_test();
	ft_bzero_test();
	ft_memcpy_test();
}

int main(void)
{
	run_libc_tests();

	return (0);
}