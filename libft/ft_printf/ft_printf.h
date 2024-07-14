/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:15:13 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/29 18:00:39 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_put_addr(void *addr);
int	ft_putnbr_base(int nbr, char *base);
int	ft_put_unsigned_nbr(unsigned int nb);
int	ft_putchar_i(char c);
int	ft_putstr(char *str);
int	ft_putx(unsigned int nbr, char *base);

#endif
