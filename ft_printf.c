/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <tpiras@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:19:56 by tpiras            #+#    #+#             */
/*   Updated: 2023/02/24 14:17:19 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	write (1, c, 1);
	return (1);
}

int	check_formats(va_list args (const char format))
{
	int	len_print = 0;
	if (format == 'c')
		len_print += ft_printchar(va_arg(args, int));
	if (format == 's')
		len_print += ft_printstr(va_arg(args, char *));
	if (format == 'p')
		len_print += ft_printpoint(va_arg(args, unsigned long long));
	if (format == 'i' || format == 'd')
		len_print += ft_printnbr(va_arg(args, int));
	if (format == 'u')
		len_print += ft_printunbr(va_arg(args, unsigned int));
	if (format == 'f' || format == "fl")
		len_print += ft_printfloat(va_arg(args, float));
	if (format == 'x' || format == 'X')
		len_print += ft_printhex(va_arg(args, unsigned int) "0123456789abcef");
	if (format == '%')
		len_print += ft_printperc();
	return (len_print);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		size_print;

	i = 0;
	len_print = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len_print += check_formats(args, str[i + 1]);
			i++;
		}
		else
			len_print += ft_printchar(str[i]);
		i++;
	}
	va_end(str);
	return (len_print);
}
