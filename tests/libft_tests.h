/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tests.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:52:26 by rgrochow          #+#    #+#             */
/*   Updated: 2024/04/05 12:46:26 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TESTS_H
# define LIBFT_TESTS_H

int	generate_strings_length1(char *c);
int	generate_strings_length2(char *c);
int	generate_strings_length3(char *c);

void	ft_memset_test(void);
void	ft_bzero_test(void);
void	ft_memcpy_test(void);
void	ft_memccpy_test(void);
void	ft_memmove_test(void);
void	ft_memchr_test(void);
void	ft_memcmp_test(void);
void	ft_strlen_test(void);
void	ft_strlcpy_test(void);
void	ft_strlcat_test(void);
void	ft_strchr_test(void);
void	ft_strrchr_test(void);
void	ft_strnstr_test(void);
void	ft_strncmp_test(void);
void	ft_atoi_test(void);
void	ft_isalpha_test(void);
void	ft_isdigit_test(void);
void	ft_isalnum_test(void);
void	ft_isascii_test(void);
void	ft_isprint_test(void);
void	ft_toupper_test(void);
void	ft_tolower_test(void);
void	ft_calloc_test(void);
void	ft_strdup_test(void);
void	ft_substr_test(void);
void	ft_strjoin_test(void);
void	ft_strtrim_test(void);
void	ft_split_test(void);
void	ft_itoa_test(void);
void	ft_strmapi_test(void);
void	ft_putchar_fd_test(void);
void	ft_putstr_fd_test(void);
void	ft_putendl_fd_test(void);
void	ft_putnbr_fd_test(void);
void	ft_lstnew_test(void);
void	ft_lstadd_front_test(void);
void	ft_lstsize_test(void);
void	ft_lstlast_test(void);
void	ft_lstadd_back_test(void);
void	ft_lstdelone_test(void);
void	ft_lstclear_test(void);
void	ft_lstiter_test(void);
void	ft_lstmap_test(void);

#endif
