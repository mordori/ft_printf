/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:26:33 by myli-pen          #+#    #+#             */
/*   Updated: 2025/05/11 22:51:05 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates memory and returns a substring from the string `s`.
 *
 * @param s Source string.
 * @param start Starting index for the substring in `s`.
 * @param len Maximum length of the substring.
 * @return New substring from `s`.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (ft_strlen(s) > start)
		while (s[start + i] && i < len)
			++i;
	sub = ft_calloc(i + 1, sizeof (char));
	if (sub && i)
		ft_memcpy(sub, &s[start], i);
	return (sub);
}
