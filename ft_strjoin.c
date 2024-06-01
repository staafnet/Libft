/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:26:45 by rgrochow          #+#    #+#             */
/*   Updated: 2024/05/31 20:08:16 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	joined = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!joined)
		return (NULL);
	ft_memcpy(joined, s1, len_s1);
	ft_memcpy(joined + len_s1, s2, len_s2 + 1);
	return (joined);
}
