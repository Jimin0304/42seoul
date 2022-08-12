/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:14:31 by jimpark           #+#    #+#             */
/*   Updated: 2022/08/12 22:50:14 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define BUFFER_SIZE 42

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

char	*make_new_buffer(char *buffer, int str_size, char *save, char *res)
{
	int	i;

	// 바로 전 문장 중간에 개행이 있었을 때
	if (*save)
	{
		buffer = ft_strjoin(save, buffer);
		str_size = ft_strlen(buffer);
	}

	while (i < str_size && !buffer[i])
	{
		if (buffer[i] == '\n')
		{
			ft_strlcpy(res, buffer, i);
			ft_strlcpy(save, &buffer[i], str_size - i);
			return (res);
		}
		i++;
	}

	// 파일이 끝났을 때
	if (i < str_size)
	{
		ft_strlcpy(res, buffer, i);
		return (res);
	}
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char		*res;
	int			i;
	static char	*save;
	int			str_size;

	if (fd < 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (0);
	read(fd, buffer, BUFFER_SIZE);
	i = 0;
	str_size = BUFFER_SIZE;

	// 엔터가 없었을 때
	buffer = buffer_realloc(buffer);
	read(fd, &buffer[i], BUFFER_SIZE);
}
