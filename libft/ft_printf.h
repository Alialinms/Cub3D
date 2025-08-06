/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:45:30 by alhamdan          #+#    #+#             */
/*   Updated: 2024/09/13 15:45:39 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include "libft.h"

char	*ft_unsigneditoa(unsigned int n);
void	itoh(va_list args, unsigned long p, int *count);
void	itoh_upper(va_list args, unsigned long p, int *count);
void	ft_ptr(va_list args, int *count);
int		str(va_list args);
int		ft_chr(va_list args);
int		num(va_list args);
int		ft_printf(const char *str, ...);
int		ft_unsignednum(va_list args);

#endif
