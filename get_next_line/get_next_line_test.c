/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:14:31 by jimpark           #+#    #+#             */
/*   Updated: 2022/08/18 16:26:51 by jimpark          ###   ########.fr       */
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

#include <stdio.h>

char	*make_new_buffer(char *buffer, int str_size, char *save)
{
	int		i;
	char	*result;

	save = ft_strjoin(save, buffer);
	//printf("save: %s", save);
	//free(buffer);
	str_size = ft_strlen(save);
	i = 0;
	while (i < str_size && save[i] != '\0')
	{
		if (save[i] == '\n')
		{
			result = (char *)malloc(sizeof(char) * (i + 2));
			if (!result)
				return (0);
			ft_strlcpy(result, save, i + 2);
			save = ft_strdup(save + (i + 1));
			//printf("save:%s", save);
			return (result);
		}
		i++;
	}
	// 파일이 끝났을 때
	if (i < str_size)
	{
		result = (char *)malloc(sizeof(char) * (i + 1));
		if (!result)
			return (0);
		ft_strlcpy(result, save, (i + 1));
		free(save);
		return (result);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*res;
	static char	*save;
	int			str_size;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	read(fd, buffer, BUFFER_SIZE);
	res = make_new_buffer(buffer, str_size, save);
	// while (res == 0)  // 엔터가 없었을 때
	// {
	// 	buffer = buffer_realloc(buffer);
	// 	read(fd, buffer, BUFFER_SIZE);
	// 	res = make_new_buffer(buffer, str_size, save);
	// }
	return (res);
}

#include <fcntl.h>

int main()
{
	char *s1;

	int main_fd = open("TEXT.txt", O_RDONLY);
	int main_i = -1;

	while (++main_i < 2)
	{
		s1 = get_next_line(main_fd);
		//printf("%s", s1);
		free(s1);
	}

	//system("leaks a.out");
	return (0);
}
