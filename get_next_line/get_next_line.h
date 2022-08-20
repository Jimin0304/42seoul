/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:56:15 by jimpark           #+#    #+#             */
/*   Updated: 2022/08/20 21:54:18 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H__
# define __GET_NEXT_LINE_H__

// #ifndef __BUFFER_SIZE__
// # define BUFFER_SIZE 10
// #endif

#include <stdlib.h>
#include <unistd.h>

char	*buffer_realloc(char *buffer, int fd);
char	*make_new_buffer(char *buffer, int str_size, char *save);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);

#endif
