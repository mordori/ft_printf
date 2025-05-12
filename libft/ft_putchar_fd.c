/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:45:37 by myli-pen          #+#    #+#             */
/*   Updated: 2025/05/11 22:19:52 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Outputs character `c` to the specified file descriptor.
 *
 * @param c Character to output.
 * @param fd File descriptor.
 * @return Number of characters written, -1 on error or only partial write.
 */
int	ft_putchar_fd(char c, int fd)
{
	int	bytes;

	bytes = write (fd, &c, 1);
	if (bytes < 1)
		return (-1);
	return (bytes);
}
