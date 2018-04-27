/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:45:40 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/24 19:45:42 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/function.h"

void	fun_add(t_map *map)
{
	int     i;
    int     num_reg;
    int		res;
    int     carry;

	ready_arg(map);
	res = map->ready_arg[0][0] + map->ready_arg[1][0];
    if (res)
        carry = 0;
    else
        carry = 1;
	i = 4;
   	num_reg = map->ready_arg[2][1];
    while (i--)
    {
        map->rg[num_reg][i] = res;
        res = res >> 8;
    }
}
