/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_xor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:31:00 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/24 19:31:02 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/function.h"

// static void	fun_xor_reg(t_map *map, int res)
// {
// 	int     i;
//     int     num_reg;

// 	i = 4;
//    	num_reg = map->ready_arg[2][1];
//     while (i--)
//     {
//         map->rg[num_reg][i] = res;
//         res = res >> 8;
//     }
// }

// static void	fun_xor_dir(t_map *map, int res)
// {
// 	int 	i;
// 	int 	curr;

// 	curr = map->pc;
// 	i = 4;
// 	while (i--)
// 	{
// 		CODE_OF_BOT[curr + 1 + i] = res;
// 		res = res >> 8;
// 	}
// }

// static void	fun_xor_ind(t_map *map, int res)
// {
// 	int		step;

// 	step = map->pc + map->ready_arg[1][0] + map->ready_arg[2][0];
//     CODE_OF_BOT[map->pc + step] = map->ready_arg[0][0];
// }

void    fun_xor(t_map *map)
{
    int     k;
    int     res;
    int     carry;
    int     i;
    int     num_reg;
    
    test_show_me_label_arg(map);
    ready_arg(map);
    res = map->ready_arg[0][0] ^ map->ready_arg[1][0];
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
    test_show_me_label_arg(map);
}


