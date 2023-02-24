/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:59:20 by tpiras            #+#    #+#             */
/*   Updated: 2023/02/24 14:09:23 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF.H
# define FT_PRINTF.H

# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

int		ft_putchar(char c);
int		check_formats(va_list args, const char format);
int		ft_printf(const char *str, ...);
int		ft_printstr(char *str);
int		ft_printnbr(int n);
int		ft_printperc(void);
int		ft_printpoint(unsigned long long ptr);
int		ft_printunbr(unsigned int n);
int		unbr_len(unsigned int n);
int		ft_printfloat(float f);
int		ft_printhex(unsigned int n, const char format);
void	ft_putstr(char *str);
char	*ft_unitoa(unsigned int n);

#endif
