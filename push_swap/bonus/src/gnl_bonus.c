/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:50:27 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/08 16:59:00 by jimpark          ###   ########.fr       */
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
		exit(1);
	buf_len = read(fd, buffer, BUFFER_SIZE);
	while (buf_len > 0)
	{
		buffer[buf_len] = '\0';
		save = ft_strjoin(save, buffer);
		if (ft_strchr(save, '\n') != 0 || !save)
			break ;
		buf_len = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (save);
}

char	*check(char *line)
{
	int		i;
	char	*res;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	res = ft_strdup(&line[i + 1]);
	if (!res)
		return (NULL);
	line[i + 1] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*result;

	if (fd < 0 || BUFFER_SIZE < 1)
		exit(1);
	result = read_file(save, fd);
	if (!result)
		return (0);
	save = check(result);
	return (result);
}
