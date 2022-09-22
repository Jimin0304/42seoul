/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:45:45 by jimpark           #+#    #+#             */
/*   Updated: 2022/09/22 19:44:29 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_file(char *save, int fd)
{
	char	*buffer;
	int		buf_len;
	char	*temp;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	while (1)
	{
		buf_len = read(fd, buffer, BUFFER_SIZE);
		if (buf_len <= 0)
			break ;
		buffer[buf_len] = '\0';
		temp = save;
		save = ft_strjoin(save, buffer);
		free (temp);
		if (ft_strchr(save, '\n') != 0 || buf_len < BUFFER_SIZE)
			break ;
	}
	free(buffer);
	if (buf_len < 0)
		return (0);
	return (save);
}

char	*read_line(char *save, int len)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	if (*save == '\0')
	{
		free (result);
		return (0);
	}
	ft_strlcpy(result, save, len + 1);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*save;
	int			i;
	char		*result;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	save = read_file(save, fd);
	if (!save)
		return (0);
	i = 0;
	while (save[i] != '\0')
	{
		if (save[i] == '\n')
		{
			result = read_line(save, i + 1);
			temp = save;
			save = ft_strdup(&(save[i + 1]));
			free (temp);
			return (result);
		}
		i++;
	}
	result = read_line(save, i);
	free(save);
	save = NULL;
	return (result);
}
