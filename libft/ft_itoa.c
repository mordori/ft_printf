/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:42:36 by myli-pen          #+#    #+#             */
/*   Updated: 2025/05/02 15:00:11 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Counts the number of digits in `n`.
 *
 * @param n Integer number.
 * @return Number of digits in an integer.
 */
static int	ft_count_digits(int n)
{
	int	count;

	if (!n)
		return (1);
	count = 0;
	while (n)
	{
		++count;
		n /= 10;
	}
	return (count);
}

/**
 * Allocates memory and converts `n` to a string.
 *
 * Handles negative numbers.
 *
 * @param n Integer to be converted.
 * @return String of the converted integer.
 */
char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		digits;

	digits = ft_count_digits(n);
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		++digits;
	}
	str = ft_calloc(digits + 1, sizeof (char));
	if (!str)
		return (NULL);
	while (digits--)
	{
		str[digits] = n % 10 * sign + '0';
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
