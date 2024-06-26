/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:50:18 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/08 16:52:55 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_BONUS_H
# define GNL_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
int		ft_strlcpy(char *dst, char *src, int dstsize);
int		ft_strlcat(char *dst, char *src, int dstsize);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);

#endif
