/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** helper
*/

#include "corewar.h"

int helper(void)
{
    print("USAGE\n./corewar [-dump nbr_cycle] [[-n prog_number] ");
    print("[-a load_address] prog_name] ...\nDESCRIPTION\n-dump nbr_cycle");
    print(" dumps the memory after the nbr_cycle execution (if the round ");
    print("isn't already over) with the following format: 32 bytes/line in ");
    print("hexadecimal (A0BCDEFE1DD3...)\n-n prog_number sets the next ");
    print("program's number. By default, the first free number in the ");
    print("parameter order\n-a load_address sets the next program's loading ");
    print("address. When no address is specified, optimize the addresses so ");
    print("that the processes are as far away from each other as possible. ");
    print("The addresses are MEM_SIZE modulo.\n");
    return 0;
}
