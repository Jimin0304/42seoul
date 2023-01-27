/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:08:54 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/19 23:04:00 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 42

char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
int		ft_strlcpy(char *dst, char *src, int dstsize);
int		ft_strlcat(char *dst, char *src, int dstsize);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);

#endif
