/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:58:15 by mkitano           #+#    #+#             */
/*   Updated: 2025/08/09 11:58:18 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(char specifier, va_list ap)
{
	if (specifier == '%')
		return (ft_putchar(specifier));
	else if (specifier == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (specifier == 'p')
		return (ft_address_hex(va_arg(ap, void *)));
	else if ((specifier == 'd') || (specifier == 'i'))
		return (ft_putnbr_dec(va_arg(ap, int)));
	else if (specifier == 'u')
		return (ft_putnbr_u(va_arg(ap, unsigned int)));
	else if ((specifier == 'x') || (specifier == 'X'))
		return (ft_putnbr_hex((unsigned long)va_arg(ap, unsigned int), specifier));
	else
		return (ft_putchar(specifier));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	i = 0;
	va_start(ap, format);
	count = 0;
	if (!format)
		return (count);
	while (format[i] != '\0')
	{
		if ((format[i] == '%') && (ft_strchr("cspdiuxX%", format[++i])))
			count += print_format((format[i]), ap);
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
