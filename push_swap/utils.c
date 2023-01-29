/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:02:40 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/28 22:08:24 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*print_err(int i)
{
	if (i == -1)
		ft_printf("Error\n");
	exit(1);
}

void	free_all(char **arr, int i)
{
	int	j;

	j = 0;
	while (j <= i)
		free(arr[j++]);
	free(arr);
}
