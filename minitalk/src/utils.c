/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:38:19 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/12 17:57:44 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	print_err(char *str)
{
	ft_printf("%s\n", str);
	exit (1);
}

int	ft_atoi(char *str)
{
	unsigned long long	result;
	int					pos;

	pos = 1;
	result = 0;
	while ((9 <= *str && *str <= 13) || (*str == 32))
		str++;
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			pos *= -1;
		str++;
	}
	if ((*str == '+') || (*str == '-'))
		return (0);
	while (('0' <= *str) && (*str <= '9'))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if ((result > 9223372036854775807) && (pos == 1))
		return (-1);
	else if ((result > 9223372036854775808ULL) && (pos == -1))
		return (0);
	return (result * pos);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
