/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:59:54 by myli-pen          #+#    #+#             */
/*   Updated: 2025/05/11 22:25:43 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Outputs string `s` to the specified file descriptor.
 *
 * @param s Source string.
 * @param fd File descriptor.
 * @return Number of characters written, -1 on error or only partial write.
 */
int	ft_putstr_fd(char *s, int fd)
{
	int	bytes;
	int	buffer;

	if (!s)
		return (-1);
	buffer = (int)ft_strlen(s);
	bytes = write (fd, s, buffer);
	if (bytes < buffer)
		return (-1);
	return (bytes);
}
