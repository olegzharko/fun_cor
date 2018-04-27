/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_lld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 11:00:15 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/26 11:00:17 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/function.h"

/*
** для T_IND не определен способ записи
*/

static	void	fun_lld_second_dir(t_map *map)
{
	int		i;
	int		res;
	int		num_reg;

	res = map->ready_arg[0][0];
	if (res)
		carry = 0;
	else
		carry = 1;
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

static	void	fun_lld_second_ind(t_map *map)
{
	int		carry;
	int		step;
	int		res;
	int		r;
	int		num_reg;

	step = map->ready_arg[0][0];
	num_reg = map->ready_arg[1][1];
	carry = 0;
	res = 0;
	r = 0;
	while (r < 2)
	{
		res = res << 8;
		res = res | CODE_OF_BOT[map->pc + step++];
		r++;
	}
	if (res)
		carry = 0;
	else
		carry = 1;
	r = 0;
	while (r < 4)
	{
		map->rg[num_reg][r] = map->rg[num_reg][r] << 8;
		map->rg[num_reg][r] = map->rg[num_reg][r] | res;
		r++;
	}
}

void	fun_lld(t_map *map)
{
	ready_arg(map);
	if (arg[0] == 2)
		fun_lld_second_dir(map);
	if (arg[0] == 3)
		fun_lld_second_ind(map);
}

