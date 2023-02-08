/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:31:21 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/07 19:16:22 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	print_err(void);

int	ft_atoi(char *str)
{
	long long	result;
	int			pos;

	pos = 1;
	result = 0;
	if (*str == '-')
	{
		pos = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (*str == '\0')
		print_err();
	while (('0' <= *str) && (*str <= '9'))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0')
		return (print_err());
	result *= pos;
	if ((result > 2147483647) || (result < -2147483648))
		return (print_err());
	return (result);
}
