/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putudem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:49:44 by jimpark           #+#    #+#             */
/*   Updated: 2022/12/23 03:47:39 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putudem(unsigned int unbr)
{
	int			len;
	char		*result;

	len = ft_unbrlen(unbr);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (-1);
	result[len--] = '\0';
	while (len >= 0)
	{
		result[len--] = "0123456789"[unbr % 10];
		unbr = unbr / 10;
	}
	len = ft_putstr(result);
	free (result);
	return (len);
}
