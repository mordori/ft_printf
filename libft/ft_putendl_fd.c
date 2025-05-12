/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:07:01 by myli-pen          #+#    #+#             */
/*   Updated: 2025/05/11 22:21:14 by myli-pen         ###   ########.fr       */
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
int	ft_putendl_fd(char *s, int fd)
{
	int	bytes;

	if (!s)
		return (-1);
	bytes = ft_putstr_fd(s, fd);
	if (bytes == -1)
		return (-1);
	if (write (fd, "\n", 1) == -1)
		return (-1);
	return (bytes + 1);
}
