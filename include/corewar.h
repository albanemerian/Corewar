/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** robot
*/

#include "my.h"
#include "printf.h"
#include "op.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef ROBOT_H_
    #define ROBOT_H_


typedef struct corewar_s {
    int nb_cycle;
    char **ids;
    int *adresses;
    char *adresse;
    char *id;
    int cycle_to_die;
    int live_cycle;
    int total_cycle;
    size_t temp_size;
    unsigned char arena[MEM_SIZE];
    char *dump;
    bool dump_flag;
    int nb_player;
    int num;
    int num_fork;
    struct player *player;
    bool bool_id;
    bool bool_adress;
}corewar_t;

struct player {
    unsigned int magic;
    char *name;
    char *comment;
    int cd;
    int size;
    int id;
    int adress;
    int pc;
    int inst_pos;
    int carry;
    int types[T_TYPES];
    int live;
    int reg[REG_NUMBER];
    bool alive;
    char *instructions;
    int (*action)(corewar_t *, struct player *);
    struct player *next;
    struct player *prev;
};

//free functions
void free_func(corewar_t *corewar);

//init functions
void init_struct(corewar_t *corewar);
int creat_list(struct player **head, corewar_t *corewar, char *file,
    unsigned char *buffer);
int return_magic(struct player *new_node, unsigned char *buffer,
    char *file, corewar_t *corewar);

//analising of parameters and files
int analyse_hexa(corewar_t *corewar, char *flag);
int handle_flags(corewar_t *corewar, char **flag, int *i);
int analyse_params(int ac, char **av);
int helper(void);
int handle_file(corewar_t *corwar, char **champion, char *file);
int load_adresses(corewar_t *corewar, char **flag, int *i);
int first_champion(corewar_t *corewar, char **flag, int *i);
void print_player(corewar_t *corewar);
//init arena
int init_arena(corewar_t *corewar);
void restart_cycle(corewar_t *corewar);
void make_instruction(corewar_t *corewar, struct player *current);

//handle for cmds
void create_action(struct player *current, corewar_t *corewar);
bool check_live(corewar_t *corewar);
void calculate_pc(struct player *current);
char *hex_byte(struct player *current, unsigned char hex_byte);
void find_type(struct player *current, char *binary);
void restart_type(struct player *current);
bool check_memory(corewar_t *corewar);
void print_arena(unsigned char arena[MEM_SIZE], corewar_t *corewar);

//instructions
int add(corewar_t *corewar, struct player *player);
int aff(corewar_t *corewar, struct player *player);
int and_cmd(corewar_t *corewar, struct player *player);
int fork_cmd(corewar_t *corewar, struct player *player);
int ld_cmd(corewar_t *corewar, struct player *player);
int ldi(corewar_t *corewar, struct player *player);
int lfork(corewar_t *corewar, struct player *player);
int live(corewar_t *corewar, struct player *player);
int lld(corewar_t *corewar, struct player *player);
int lldi(corewar_t *corewar, struct player *player);
int or_cmd(corewar_t *corewar, struct player *player);
int st_cmd(corewar_t *corewar, struct player *player);
int sti(corewar_t *corewar, struct player *player);
int sub(corewar_t *corewar, struct player *player);
int xor_cmd(corewar_t *corewar, struct player *player);
int zjmp(corewar_t *corewar, struct player *player);
void cp_reg(struct player *new_player, int reg[REG_NUMBER]);
void place_player(corewar_t *corewar, struct player *new_player);
#endif /* !ROBOT_H_ */
