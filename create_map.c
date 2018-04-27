//
//  create_map.c
//  pr_corewar
//
//  Created by Kostiantyn MYKHAILENKO on 4/21/18.
//  Copyright © 2018 Kostiantyn MYKHAILENKO. All rights reserved.
//

#include "../inc/function.h"

/*
** главная функция по которой ходит каретка
*/

void	ft_walk_on_array(t_map *map)
{
	test_open(map);
    int i = 0;
    while (i < map->cnt_bot)				//
        dprintf(FD, "%x  ", CODE_OF_BOT[i++]);   // распечать самого бота, без карты;
    dprintf(FD, "\n");							//

    map->pc = 0;
	while (1)
	{
        dprintf(FD, "index:%d value:%d\n", map->pc, CODE_OF_BOT[map->pc]);   // где стала каретка (отлов команды);
		STEP = 1;
        
		if (CODE_OF_BOT[map->pc] >= 16)
			exit(1);
		if (CODE_OF_BOT[map->pc] != 1 &&  CODE_OF_BOT[map->pc] != 8 && CODE_OF_BOT[map->pc] != 12 && CODE_OF_BOT[map->pc] != 15 && CODE_OF_BOT[map->pc] != 16)
		{
			if (map->pc + 1 < map->cnt_bot) 					// что дает этот cnt_bot ?? для чего сравнени ?? ?????? map->cnt_bot - это вся длинна бота??
				ft_check_codage(map, CODE_OF_BOT[map->pc + 1]);
			else
				exit(1);
            ft_implement_command(map, map->pc);
            STEP += ft_step_pc(map, CODE_OF_BOT[map->pc]);
			map->pc += STEP;
		}
		else
		{
            STEP = map->label[map->pc][3];
            map->pc += STEP;
		}
		map->pc++;
	}
}



