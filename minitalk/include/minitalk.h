/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:17:05 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/12 17:58:01 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "../lib/ft_printf/ft_printf.h"

int		ft_atoi(char *str);
void	print_err(char *str);
int		ft_strlen(char *s);

#endif
