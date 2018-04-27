/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_zjmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:14:48 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/24 18:14:50 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/function.h"

/*
** CARRY 
*/

void	fun_zjmp(t_map *map)
{
	int		carry;
	int		num;

	carry = 0;
	num = 0;
	if (carry == 1)
	{
		ready_arg(map);
		num = ready_arg[0][0] % IDX_MOD;
		map->pc = map->pc + num;
	}

}