/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <tpiras@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:19:56 by tpiras            #+#    #+#             */
/*   Updated: 2023/02/21 15:09:05 by tpiras           ###   ########.fr       */
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
	int	size_print = 0;
	if (format == 'c')
		size_print += ft_printchar(va_arg(args, int));
	if (format == 's')
		size_print += ft_printstring(va_arg(args, char *));
	if (format == 'p')
		size_print += ft_printpoint(va_arg(args, unsigned long long));
	if (format == 'i' || format == 'd')
		size_print += ft_printnbr(va_arg(args, int));
	if (format == 'u')
		size_print += ft_printuns(va_arg(args, unsigned int));
	if (format == 'f' || format == "fl")
		size_print += ft_printfloat(va_arg(args, float));
	if (format == 'x' || format == 'X')
		size_print += ft_printhex(va_arg(args, unsigned int) format);
	if (format == '%')
		size_print += ft_printperc();
	return (size_print);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		size_print;

	i = 0;
	size_print = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size_print += check_formats(args, str[i + 1]);
			i++;
		}
		else
			size_print += ft_printchar(str[i]);
		i++;
	}
	va_end(str);
	return (size_print);
}
