/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:15:30 by jimpark           #+#    #+#             */
/*   Updated: 2022/08/02 22:51:10 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	result;
	int	count;

	i = 0;
	count = 0;
	result = i;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			result = i;
			count++;
		}
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	if (count == 0)
		return (0);
	else
		return ((char *)&s[result]);
}
