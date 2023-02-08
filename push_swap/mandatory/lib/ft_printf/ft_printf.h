/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:46:08 by jimpark           #+#    #+#             */
/*   Updated: 2022/12/23 03:47:34 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *strformat, ...);
int	ft_putchar(int nbr);
int	ft_putdem(int nbr);
int	ft_puthex(unsigned int hexnbr, char type);
int	ft_putpt(void *point);
int	ft_putstr(char *s);
int	ft_putudem(unsigned int unbr);
int	ft_nbrlen(long long n);
int	ft_unbrlen(unsigned int n);
int	ft_hexlen(unsigned long long n);

#endif
