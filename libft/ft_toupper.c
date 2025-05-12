/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:36:03 by myli-pen          #+#    #+#             */
/*   Updated: 2025/05/12 00:32:38 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Converts lowercase alphabet character `a-z` to uppercase.
 *
 * @param c Character to be converted.
 * @return `A-Z`, otherwise `c`.
 */
int	ft_toupper(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 'a' - 'A';
	return (*c);
}
