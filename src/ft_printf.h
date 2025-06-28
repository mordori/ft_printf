/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:08:49 by myli-pen          #+#    #+#             */
/*   Updated: 2025/06/28 22:34:31 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>		// va_list, va_start, va_arg, va_end
# include "../libft/libft.h"

# define BASE_10 "0123456789"
# define BASE_16 "0123456789ABCDEF"

int		ft_printf(const char *str, ...);
char	*ft_uitoa(uintptr_t n, const char *base);

#endif
