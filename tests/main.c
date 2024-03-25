/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:14:48 by rgrochow          #+#    #+#             */
/*   Updated: 2024/03/23 22:28:39 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

void run_libc_tests(void)
{
	ft_memset_test();
	ft_bzero_test();
	ft_memcpy_test();
	ft_memccpy_test();
	ft_memmove_test();
	ft_memchr_test();
	ft_memcmp_test();
	ft_strlen_test();
	ft_strlcpy_test();
	ft_strlcat_test();
	ft_strchr_test();
	ft_strrchr_test();
	ft_strnstr_test();
	ft_strncmp_test();
	ft_atoi_test();
	ft_isalpha_test();
	ft_isdigit_test();
	ft_isalnum_test();
	ft_isascii_test();
	ft_isprint_test();
	ft_toupper_test();
	ft_tolower_test();
}

void run_additional_tests(void)
{
	ft_calloc_test();
	ft_strdup_test();
	ft_substr_test();
	ft_strjoin_test();
	ft_strtrim_test();
	ft_split_test();
	ft_itoa_test();
	ft_strmapi_test();
	ft_putchar_fd_test();
	ft_putstr_fd_test();
	ft_putendl_fd_test();
	ft_putnbr_fd_test();
}

void run_bonus_tests(void)
{
	ft_lstnew_test();
	ft_lstadd_front_test();
	ft_lstsize_test();
	ft_lstlast_test();
	ft_lstadd_back_test();
	ft_lstdelone_test();
	ft_lstclear_test();
	ft_lstiter_test();
	ft_lstmap_test();
}

int main(void)
{
	run_libc_tests();
	run_additional_tests();
	run_bonus_tests();

	return (0);
}
