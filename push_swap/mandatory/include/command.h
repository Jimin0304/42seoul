/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:06:06 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/06 21:06:54 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "struct.h"

void	sa(t_info *a_info);
void	sb(t_info *b_info);
void	ss(t_info *a_info, t_info *b_info);
void	pa(t_info *a_info, t_info *b_info);
void	pb(t_info *a_info, t_info *b_info);
void	ra(t_info *a_info);
void	rb(t_info *b_info);
void	rr(t_info *a_info, t_info *b_info);
void	rra(t_info *a_info);
void	rrb(t_info *b_info);
void	rrr(t_info *a_info, t_info *b_info);

#endif
