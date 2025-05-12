/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:07:01 by myli-pen          #+#    #+#             */
/*   Updated: 2025/05/12 18:00:04 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Outputs string `s` to the specified file descriptor followed by a newline.
 *
 * @param s Source string.
 * @param fd File descriptor.
 * @return Number of characters written, -1 on error or only partial write.
 */
ssize_t	ft_putendl_fd(char *s, int fd)
{
	ssize_t	bytes;

	if (!s)
		return (-1);
	bytes = ft_putstr_fd(s, fd);
	if (bytes == -1 || write (fd, "\n", 1) == -1)
		return (-1);
	return (bytes + 1);
}
