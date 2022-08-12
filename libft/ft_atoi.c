/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:31:21 by jimpark           #+#    #+#             */
/*   Updated: 2022/08/10 12:53:07 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
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
