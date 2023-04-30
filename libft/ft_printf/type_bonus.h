/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:05:18 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 15:05:19 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_BONUS_H
# define TYPE_BONUS_H

typedef struct s_type
{
	int				width;
	int				plus;
	int				sharp;
	int				minus;
	int				zero;
	int				blank;
	int				precision;
	int				get_num;
	char			type;
	struct s_type	*next;
}	t_type;

#endif