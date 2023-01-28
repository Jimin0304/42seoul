/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:10:45 by jimpark           #+#    #+#             */
/*   Updated: 2022/12/23 03:57:21 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(va_list *ap, char type)
{
	int	len;

	len = 0;
	if (type == 's')
		len = ft_putstr(va_arg(*ap, char *));
	else if (type == 'c')
		len = ft_putchar(va_arg(*ap, int));
	else if (type == 'd' || type == 'i')
		len = ft_putdem(va_arg(*ap, int));
	else if (type == 'u')
		len = ft_putudem(va_arg(*ap, unsigned int));
	else if (type == 'x' || type == 'X')
		len = ft_puthex(va_arg(*ap, unsigned int), type);
	else if (type == 'p')
		len = ft_putpt(va_arg(*ap, void *));
	else if (type == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *strformat, ...)
{
	va_list	ap;
	int		len;
	int		write_bytes;
	int		i;

	if (!strformat)
		return (-1);
	va_start (ap, strformat);
	len = 0;
	i = 0;
	while (strformat[i] != '\0')
	{
		if (strformat[i] == '%')
			write_bytes = ft_convert(&ap, strformat[i++ + 1]);
		else
			write_bytes = ft_putchar(strformat[i]);
		if (write_bytes == -1)
			return (-1);
		len += write_bytes;
		i++;
	}
	va_end(ap);
	return (len);
}
