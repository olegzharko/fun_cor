//
//  test.c
//  corewar
//
//  Created by Oleg ZHARKO on 4/20/18.
//  Copyright © 2018 Oleg ZHARKO. All rights reserved.
//

#include "../inc/function.h"

void    test_open(t_map *map)
{
    map->fd =  open("/Users/ozharko/Desktop/corewar/corewar/src/test.txt", O_RDONLY | O_WRONLY | O_TRUNC, 0644);
}

// int     ft_find_command(int find)
// {
//     int res;
//     int i;

//     i = 0;
//     res = 0;
//     while (i < 16)
//     {
//         if (find - 1 == i)
//         {
//             return (i);
//         }
//         i++;
//     }
//     return (res);
// }


void    test_show_me_label_arg(t_map *map)
{
    int     num;

    num = CODE_OF_BOT[map->pc];
    dprintf(FD, "_______________\n");
    dprintf(FD, "label[06][0] = %d\n", map->label[num][0]);
    dprintf(FD, "label[06][1] = %d\n", map->label[num][1]);
    dprintf(FD, "label[06][2] = %d\n", map->label[num][2]);
    dprintf(FD, "label[06][3] = %d\n", map->label[num][3]);
    dprintf(FD, "_______________\n");
    dprintf(FD, "step = %d\n", map->steper);
    dprintf(FD, "_______________\n");
    dprintf(FD, "arg[0] = %d\n", map->arg[0]);
    dprintf(FD, "arg[1] = %d\n", map->arg[1]);
    dprintf(FD, "arg[2] = %d\n", map->arg[2]);
    
    int i;
    int k;
    
    i = 0;
    while (i < 16)
    {
        k = 0;
        while (k < 4)
        {
            dprintf(FD, "[%d] ", map->rg[i][k]);
            k++;
        }
        dprintf(FD, "\n");
        i++;
    }
    dprintf(FD, "_______________________________________\n");
}
