/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:50:27 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/06 22:08:42 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/gnl_bonus.h"

char	*ft_strdup(char *s1)
{
	int		size;
	char	*dest;
	int		i;

	size = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (0);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*read_file(char *save, int fd)
{
	char	*buffer;
	int		buf_len;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	buf_len = read(fd, buffer, BUFFER_SIZE);
	while (buf_len > 0)
	{
		buffer[buf_len] = '\0';
		save = ft_strjoin(save, buffer);
		if (!save)
			return (0);
		if (ft_strchr(save, '\n') != 0 || buf_len < BUFFER_SIZE)
			break ;
		buf_len = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (buf_len < 0)
	{
		free (save);
		return (0);
	}
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

char	*get_save(char *save, int i)
{
	char	*temp;

	temp = save;
	save = ft_strdup(&(save[i + 1]));
	if (!save)
		return (0);
	free (temp);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	int			i;
	char		*result;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	save = read_file(save, fd);
	if (!save)
		return (0);
	i = -1;
	while (save[++i] != '\0')
	{
		if (save[i] == '\n')
		{
			result = read_line(save, i + 1);
			save = get_save(save, i);
			if (!save)
				return (0);
			return (result);
		}
	}
	result = read_line(save, i);
	free(save);
	save = NULL;
	return (result);
}
