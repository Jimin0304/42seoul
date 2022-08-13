/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:14:31 by jimpark           #+#    #+#             */
/*   Updated: 2022/08/13 17:47:02 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buffer_realloc(char *buffer)
{
	char	*temp;
	int		i;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE * 2));
	if (!temp)
		return (0);
	i = 0;
	while (i < BUFFER_SIZE)
	{
		temp[i] = buffer[i];
		i++;
	}
	free(buffer);
	return (temp);
}

char	*make_new_buffer(char *buffer, int str_size, char *save)
{
	int		i;
	char	*res;

	res = NULL;
	// 바로 전 문장 중간에 개행이 있었을 때
	if (*save)
	{
		buffer = ft_strjoin(save, buffer);
		str_size = ft_strlen(buffer);
		save = NULL;
	}
	i = 0;
	while (i < str_size && !buffer[i])
	{
		if (buffer[i] == '\n')
		{
			ft_strlcpy(res, buffer, i);
			buffer += i;
			ft_strlcpy(save, buffer, str_size - i);
			free(buffer);
			return (res);
		}
		i++;
	}
	// 파일이 끝났을 때
	if (i < str_size)
	{
		ft_strlcpy(res, buffer, i);
		free(buffer);
		free(save);
		return (res);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*res;
	static char	*save;

	if (fd < 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (0);
	read(fd, buffer, BUFFER_SIZE);
	res = make_new_buffer(buffer, BUFFER_SIZE, save);
	while (res == 0)  // 엔터가 없었을 때
	{
		buffer = buffer_realloc(buffer);
		read(fd, buffer, BUFFER_SIZE);
		res = make_new_buffer(buffer, BUFFER_SIZE, save);
	}
	return (res);
}
