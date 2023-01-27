/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:25:37 by jimpark           #+#    #+#             */
/*   Updated: 2022/11/11 19:37:58 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

t_list	*find_node(int fd, t_list *head)
{
	t_list	*newnode;

	if (!head)
	{
		head = (t_list *)malloc(sizeof(t_list));
		if (!head)
			return (0);
		head->fd = fd;
		head->save = NULL;
		head->prev = NULL;
		return (head);
	}
	while (head)
	{
		if (head->fd == fd)
			return (head);
		head = head->next;
	}
	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (0);
	head->next = newnode;
	head->fd = fd;
	newnode->prev = head;
	return (newnode);
}

void	free_node(t_list *fdnode)
{
	free(fdnode->save);
	fdnode->save = NULL;
	free(fdnode);
}

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
		if (!save)
			return (0);
		free (temp);
		if (ft_strchr(save, '\n') != 0 || buf_len < BUFFER_SIZE)
			break ;
	}
	free(buffer);
	if (buf_len < 0)
		return (0);
	return (save);
}

char	*read_line(char	*save, int len)
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
	static t_list	*fdnode;
	int				i;
	char			*result;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	fdnode = find_node(fd, fdnode);
	fdnode->save = read_file(fdnode->save, fd);
	if (!(fdnode->save))
		return (0);
	i = -1;
	while (fdnode->save[++i] != '\0')
	{
		if (fdnode->save[i] == '\n')
		{
			result = read_line(fdnode->save, i + 1);
			fdnode->save = get_save(fdnode->save, i);
			if (!(fdnode->save))
				return (0);
			return (result);
		}
	}
	result = read_line(fdnode->save, i);
	free(fdnode->save);
	//fdnode->save = NULL;
	free(fdnode);
	fdnode = NULL;
	return (result);
}

int main(void) {
	int fd;
	char *str;

	fd = open("text.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%p %s", str, str);
	str = get_next_line(fd);
	printf("%p %s", str, str);
	str = get_next_line(fd);
	printf("%p %s", str, str);
	str = get_next_line(fd);
	printf("%p %s", str, str);
}
