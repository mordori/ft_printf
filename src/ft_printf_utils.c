/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:24:42 by myli-pen          #+#    #+#             */
/*   Updated: 2025/05/12 16:21:05 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Counts the number of digits in `n` with a specified base.
 *
 * @param n Integer number.
 * @param len Number of characters in the base used.
 * @return Number of digits in an integer number.
 */
static int	ft_countdigits(uintptr_t n, const size_t len)
{
	unsigned int	count;

	if (!len)
		return (-1);
	count = 1;
	n /= len;
	while (n)
	{
		++count;
		n /= len;
	}
	return (count);
}

/**
 * Validates `base` with the following rules:
 *
 * - Begins with digits 0-9 in ascending order
 *
 * - Has atleast 2 digits
 *
 * - A-Z in ascending order after the 10th digit.
 *
 * @param base Source string.
 * @return `1` if `base` is valid, `0` if not.
 */
static int	ft_validatebase(const char *base)
{
	int	i;
	int	j;

	if (!base || !*base)
		return (0);
	i = 0;
	while (i < 10 && base[i] == i + '0')
		++i;
	if (i < 2 || (base[i] && i < 10))
		return (0);
	j = 0;
	while (base[i + j])
	{
		if (base[i + j] != j + 'A')
			return (0);
		++j;
	}
	return (1);
}

/**
 * Converts the unsigned integer `n` of `base` to a newly allocated string.
 * The base is validated.
 *
 * @param n Number to be converted.
 * @param base Base of the number.
 * @return String of the converted number.
 */
char	*ft_uitoa(uintptr_t n, const char *base)
{
	char	*str;
	int		digits;
	size_t	len;

	if (!ft_validatebase(base))
		return (NULL);
	len = ft_strlen(base);
	digits = ft_countdigits(n, len);
	str = ft_calloc(digits + 1, sizeof (char));
	if (!str)
		return (NULL);
	while (digits--)
	{
		str[digits] = base[n % len];
		n /= len;
	}
	return (str);
}
