/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_current.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:08:41 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/24 11:08:42 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/function.h"

/*
** CODE_OF_BOT[map->pc + 1 + k]; прибавление 1 должно быть в виде переменной которая покажет есть ли кожэдж у данной функции
*/
void     ready_arg(t_map *map)
{
    int     i;
    int     k;
    int     r;
    int     num;
	int     test_2;
    // int     curr;
    
    // часть для значений
    map->ready_arg[0][0] = 0;
    map->ready_arg[1][0] = 0;
    map->ready_arg[2][0] = 0;
    // часть дял T_REG
    map->ready_arg[0][1] = 0;
    map->ready_arg[1][1] = 0;
    map->ready_arg[2][1] = 0;
    
    i = 0;
    k = 1;
    while (i < 3)
    {
        if (map->arg[i] == 1) 		 // (если аргумент регист в котором надо взять значение внутри)
        {
            num = CODE_OF_BOT[map->pc];
            r = 0;
            map->ready_arg[i][1] = CODE_OF_BOT[map->pc + 1 + k];  // записать номер T_REG 
            while (r < 4)
            {
                map->ready_arg[i][0] = map->ready_arg[i][0] << 8;
                test_2 = map->rg[num - 1][r];
                map->ready_arg[i][0] = map->ready_arg[i][0] | test_2;
                r++;
            }
            dprintf(FD, "map->ready->arg[%i][0] = %d\n", i, map->ready_arg[i][0]);
            k++;
        }
        else if (map->arg[i] == 2)
        {
            num = CODE_OF_BOT[map->pc];   // беру текущею позицию на карте;
            num = map->label[num][3];     // эту позицию вставляю в поиск строки в лейбл и беру размер T_DIR // num = РАЗМЕР T_DIR
            while (num--)
            {
                map->ready_arg[i][0] = map->ready_arg[i][0] << 8;
                map->ready_arg[i][0] = map->ready_arg[i][0] | CODE_OF_BOT[map->pc + 1 + k];  // 0b 68 00 00 00 01
                k++;
            }
            dprintf(FD, "map->ready->arg[%i][0] = %d\n", i, map->ready_arg[i][0]);
        }
        /*
        ** для функции ldi надо считать T_IND "4 байта считаные с позиции ((T_IND % IDX_MOD) плюс текущая позиция PC)."
        */
        else if (map->arg[i] == 3 && (CODE_OF_BOT[map->pc] == 2 || CODE_OF_BOT[map->pc] == 3 || CODE_OF_BOT[map->pc] == 10 || CODE_OF_BOT[map->pc] == 11 || CODE_OF_BOT[map->pc] == 14))
        {
            num = 0;
            num = num | CODE_OF_BOT[map->pc + 1 + k++];
            num = num << 8;
            num = num | CODE_OF_BOT[map->pc + 1 + k++];
            num = num % IDX_MOD;
            r = 0;
            while (r < 4)
            {
                map->ready_arg[i][0] = map->ready_arg[i][0] << 8;
                map->ready_arg[i][0] = map->ready_arg[i][0] | CODE_OF_BOT[map->pc + 1 + num++]; 
                r++;
            }
        }
        /*
        ** отдельное условие для ld КАК ОН ТУТ ПЕРЕЗАПИШЕТСЯ
        */
        else if (map->arg[i] == 3 && (CODE_OF_BOT[map->pc] == 2))
        {
            num = 0;
            num = num | CODE_OF_BOT[map->pc + 1 + k++];
            num = num << 8;
            num = num | CODE_OF_BOT[map->pc + 1 + k++];
            num = num % IDX_MOD; // ключевой момоент IND для этой функции
            r = 0;
            while (r < 4)
            {
                map->ready_arg[i][0] = map->ready_arg[i][0] << 8;
                map->ready_arg[i][0] = map->ready_arg[i][0] | CODE_OF_BOT[map->pc + 1 + num++]; 
                r++;
            }
        }
        else if (map->arg[i] == 3)
        {
        	num = 0;
        	num = num | CODE_OF_BOT[map->pc + 1 + k++];
        	num = num << 8;
        	num = num | CODE_OF_BOT[map->pc + 1 + k++];
        	r = 0;
        	while (r < 4)
        	{
                map->ready_arg[i][0] = map->ready_arg[i][0] << 8;
                map->ready_arg[i][0] = map->ready_arg[i][0] | CODE_OF_BOT[map->pc + 1 + num++]; 
                r++;
        	}
        }
        i++;
    }
}

int     ft_step_pc(t_map *map, int num)
{
	int     step;
	
	step = 0;
	if (map->arg[0])
	{
		if (map->arg[0] == 1)
			step += 1;
		if (map->arg[0] == 2)
			step += map->label[num][3];
		if (map->arg[0] == 3)
			step += 2;
	}
	if (map->arg[1])
	{
		if (map->arg[1] == 1)
			step += 1;
		if (map->arg[1] == 2)
			step += map->label[num][3];
		if (map->arg[1] == 3)
			step += 2;
	}
	if (map->arg[2])
	{
		if (map->arg[2] == 1)
			step += 1;
		if (map->arg[2] == 2)
			step += map->label[num][3];
	}
	map->arg[0] = 0;
	map->arg[1] = 0;
	map->arg[2] = 0;
	return (step);
}

void    ft_check_codage(t_map *map, uint8_t num)
{
	int     i;

	i = 1;
	map->codage = num;     // зачем нам знать это codage если у нас все будет в 	uint8_t arg[3];    ready_arg[3][2]; ????????????????????????????
	while (1)
	{
		if ((i == 1 || i == 2))
		{
			map->arg[0] = map->arg[0] << 1;
			map->arg[0] += (num >= 128) ? 1 : 0;
		}
		if (i == 3 || i == 4)
		{
			map->arg[1] = map->arg[1] << 1;
			map->arg[1] += (num >= 128) ? 1 : 0;
		}
		if (i == 5 || i == 6)
		{
			map->arg[2] = map->arg[2] << 1;
			map->arg[2] += (num >= 128) ? 1 :0;
		}
		if (num == 0)
			break ;
		num = num << 1;
		i++;
	}
}

