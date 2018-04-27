/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_st.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 09:54:20 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/26 09:54:22 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/function.h"

static	void	fun_st_second_reg(t_map *map)
{
	int		r;
	int		res;
	int		num_reg;

	res = map->ready_arg[0][0];
	r = 4;
	num_reg = map->ready_arg[1][1];
	while (r--)
	{
		map->rg[num_reg][i] = res;
		res = res >> 8;
	}
}

/*
** не понятно в какую ячейку надо делать запись ? T_REG или T_DIR !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

static	void	fun_st_second_ind(t_map *map)
{
	map->fd = map->fd; // ????? что тут может быть ячейкой?регистр или дир ?? или все 4 ячейки;
}

void	fun_st(t_map *map)
{
	ready_arg(map);
	if (map->arg[1] == 1)
		fun_st_second_reg(map);
	if (map->arg[1] == 3)
		fun_st_second_ind(map);
}