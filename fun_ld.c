/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_ld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 10:07:35 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/26 10:07:36 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/function.h"

/*
** для T_IND не определен способ записи
*/

static	void	fun_ld_second_reg(t_map *map)
{
	int		i;
	int		res;
	int		num_reg;

	res = map->ready_arg[0][0];
	i = 4;
	num_reg = map->ready_arg[1][1];
	while (i--)
	{
		map->rg[num_reg][i] = res;
		res = res >> 8;
	}
}

/*
** не понятно в какую ячейку надо делать запись ? T_IND !!!!!!!!!!!!!!!!!!!!!!
*/

static	void	fun_ld_second_ind(t_map *map)
{
	int		carry;
	int		step;
	int		res;
	int		r;
	int		num_reg;

	num_reg = map->ready_arg[1][1];
	carry = 0;
	res = map->ready_arg[0][0];
	if (res)
		carry = 0;
	else
		carry = 1;
	r = 0;
	while (r < 4)
	{
		map->rg[num_reg][r] = map->rg[num_reg][r] | res;
		res = res >> 8;
		r++;
	}
}

void	fun_ld(t_map *map)
{
	ready_arg(map);
	if (map->arg[0] == 1)
		fun_ld_second_reg(map);
	if (map->arg[0] == 3)
		fun_ld_second_ind(map);
}
