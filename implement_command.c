/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 09:18:50 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/24 09:18:52 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/function.h"

void	choose_function_1(t_map *map)
{
	// if (CODE_OF_BOT[map->pc] == 1)
	// 	fun_live(map);
	if (CODE_OF_BOT[map->pc] == 2)
		fun_ld(map);
	if (CODE_OF_BOT[map->pc] == 3)
		fun_st(map);
	if (CODE_OF_BOT[map->pc] == 4)
		fun_add(map);
	if (CODE_OF_BOT[map->pc] == 5)
		fun_sub(map);
	if (CODE_OF_BOT[map->pc] == 6)
		fun_and(map);
	if (CODE_OF_BOT[map->pc] == 7)
		fun_or(map);
	if (CODE_OF_BOT[map->pc] == 8)
		fun_xor(map);
}

void	choose_function_2(t_map *map)
{
	if (CODE_OF_BOT[map->pc] == 9)
		fun_zjmp(map);
	if (CODE_OF_BOT[map->pc] == 10)
		fun_ldi(map);
	if (CODE_OF_BOT[map->pc] == 11)
		fun_sti(map);
	// else if (CODE_OF_BOT[map->pc] == 12)
	// 	fun_fork(map);
	if (CODE_OF_BOT[map->pc] == 13)
		fun_lld(map);
	if (CODE_OF_BOT[map->pc] == 14)
		fun_lldi(map);
	// else if (CODE_OF_BOT[map->pc] == 15)
	// 	fun_lfork(map);
	else if (CODE_OF_BOT[map->pc] == 16)
		fun_aff(map);
}


void    ft_implement_command(t_map *map)
{
    if (CODE_OF_BOT[map->pc] >= 1 && CODE_OF_BOT[map->pc] < 9)
        choose_function_1(map);
    else if (CODE_OF_BOT[map->pc] >=9 && CODE_OF_BOT[map->pc] <= 16)
        choose_function_2(map);
}


