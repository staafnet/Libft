/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:37:13 by rgrochow          #+#    #+#             */
/*   Updated: 2024/05/31 18:38:14 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapped;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (!s || !f)
		return (NULL);
	while (s[len])
		len++;
	mapped = (char *)malloc(sizeof(char) * (len + 1));
	if (!mapped)
		return (NULL);
	while (i < len)
	{
		mapped[i] = f(i, s[i]);
		i++;
	}
	mapped[i] = '\0';
	return (mapped);
}
