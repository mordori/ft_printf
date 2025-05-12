/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:49:20 by myli-pen          #+#    #+#             */
/*   Updated: 2025/05/02 14:14:07 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Checks if `c` is a whitespace character.
 *
 * @param c Character to be checked for.
 * @return `1` if the check is true, `0` if false.
 */
static int	ft_isspace(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

/**
 * Converts the initial portion of the string `nptr` to an integer value.
 *
 * Does not handle overflow.
 *
 * In case of `NULL nptr` returns arbitrary -1.
 *
 * @param nptr Source string.
 * @return Integer value converted from the initial portion of the provided
 * string `nptr`.
 */
int	ft_atoi(const char *nptr)
{
	int	sign;
	int	number;

	if (!nptr)
		return (-1);
	while (ft_isspace(*nptr))
		++nptr;
	sign = 1;
	if ((*nptr == '-' || *nptr == '+') && *nptr++ == '-')
		sign = -1;
	number = 0;
	while (ft_isdigit(*nptr))
		number = number * 10 + (*nptr++ - '0');
	return (sign * number);
}
