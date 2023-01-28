/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:02:10 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/28 23:07:27 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

typedef struct s_node
{
	int				content;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_info
{
	int				*arr;
	int				size_a;
	int				size_b;
	struct s_node	*top_a;
	struct s_node	*bottom_a;
	struct s_node	*top_b;
	struct s_node	*bottom_b;
}				t_info;

char	*print_err(void);

#endif
