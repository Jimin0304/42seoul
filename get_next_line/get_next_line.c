/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:30:41 by jimpark           #+#    #+#             */
/*   Updated: 2022/08/18 18:53:57 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_file(char *save, int fd)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE));
	if (!buffer)
		return (0);
	read(fd, buffer, BUFFER_SIZE);
	save = ft_strjoin(save, buffer);
	free(buffer);
	return (save);
}

char	*read_line(char *save, int len)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * len);
	if (!result)
		return (0);
	ft_strlcpy(result, save, len);
	return (result);
}

char	*last_line(char *save, int len)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * len);
	if (!result)
		return (0);
	ft_strlcpy(result, save, len);
	free(save);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*save;
	int			str_size;
	int			i;
	char		*result;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	save = read_file(save, fd);
	if (!save)
		return (0);
	str_size = ft_strlen(save);
	i = 0;
	while (i < str_size && save[i] != '\0')
	{
		if (save[i] == '\n')
		{
			temp = ft_strdup(save);
			result = read_line(temp, i + 2);
			save += i + 1;
			temp = NULL;
			free(temp);
			return (result);
		}
		i++;
	}
	if (i < str_size)
		result = last_line(save, i + 1);
	return (result);
}

#include <fcntl.h>

int main()
{
	char *s1;

	int main_fd = open("TEXT.txt", O_RDONLY);
	int main_i = -1;

	while (++main_i < 4)
	{
		s1 = get_next_line(main_fd);
		printf("%s", s1);
		free(s1);
	}

	//system("leaks a.out");
	return (0);
}
