/*
** EPITECH PROJECT, 2024
** Coreware
** File description:
** init_players
*/

#include "corewar.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int check_ids(corewar_t *corewar, int temp)
{
    int num = corewar->nb_player + 1;
    struct player *current = corewar->player;

    while (current != NULL) {
        if (current->id == num) {
            num += 1;
            break;
        }
        current = current->next;
    }
    return num;
}

static void get_size(corewar_t *corewar, struct player *new_node)
{
    int num = 0;

    if (corewar->bool_id == false) {
        num = check_ids(corewar, new_node->id);
        new_node->id = num;
    } else
        new_node->id = my_getnbr(corewar->ids[corewar->nb_player]);
    if (corewar->bool_adress == false)
        new_node->adress = -1;
    else
        new_node->adress = corewar->adresses[corewar->nb_player];
    corewar->bool_adress = false;
    corewar->bool_id = false;
    new_node->pc = 0;
    new_node->carry = 0;
    new_node->live = 0;
    new_node->alive = true;
}

static int get_magic(struct player *new_node, char *file, corewar_t *corewar)
{
    unsigned int magic = 0xea83f3;
    unsigned char *buffer = NULL;
    int fd = open(file, O_RDONLY);

    buffer = malloc(sizeof(char) * corewar->temp_size + 1);
    for (int i = 0; i < 4; i++) {
        if (read(fd, &buffer[i], 1) == -1)
            return -1;
        new_node->magic = new_node->magic << 8 | buffer[i];
    }
    if (magic != new_node->magic)
            return -1;
    get_size(corewar, new_node);
    return 0;
}

static void get_name(struct player *new_node, unsigned char *buffer)
{
    for (int i = 4; i < 4 + PROG_NAME_LENGTH; i++)
        new_node->name[i - 4] = buffer[i];
    new_node->name[PROG_NAME_LENGTH] = '\0';
}

static void get_comment(struct player *new_node, unsigned char *buffer)
{
    for (int i = 12 + PROG_NAME_LENGTH; i < 12 + PROG_NAME_LENGTH +
    COMMENT_LENGTH; i++)
        new_node->comment[i - 12 - PROG_NAME_LENGTH] = buffer[i];
    new_node->comment[COMMENT_LENGTH] = '\0';
}

static void get_size_prog(struct player *new_node, unsigned char *buffer)
{
    new_node->size = buffer[4 + PROG_NAME_LENGTH];
    for (int i = 5 + PROG_NAME_LENGTH; i < 12 + PROG_NAME_LENGTH; i++) {
        new_node->size = new_node->size << 8;
        new_node->size += buffer[i];
    }
}

static void get_instructions(struct player *new_node, unsigned char *buffer)
{
    new_node->instructions = malloc(sizeof(char) * new_node->size);
    for (int i = 12 + PROG_NAME_LENGTH + COMMENT_LENGTH; i < 12 +
        PROG_NAME_LENGTH + COMMENT_LENGTH + new_node->size; i++)
        new_node->instructions[i - 12 -
            PROG_NAME_LENGTH - COMMENT_LENGTH] = buffer[i + 4];
}

int return_magic(struct player *new_node, unsigned char *buffer, char *file,
    corewar_t *corewar)
{
    new_node->name = malloc(sizeof(char) * PROG_NAME_LENGTH + 1);
    new_node->comment = malloc(sizeof(char) * COMMENT_LENGTH + 1);
    if (get_magic(new_node, file, corewar) == -1)
        return -1;
    get_name(new_node, buffer);
    get_comment(new_node, buffer);
    get_size_prog(new_node, buffer);
    get_instructions(new_node, buffer);
    new_node->alive = true;
    new_node->cd = 0;
    new_node->action = NULL;
    new_node->next = NULL;
    corewar->num += 1;
    return 0;
}

int creat_list(struct player **head, corewar_t *corewar, char *file,
    unsigned char *buffer)
{
    struct player *new_node = NULL;
    struct player *current = NULL;

    new_node = malloc(sizeof(struct player));
    if (new_node == NULL)
        return 84;
    if (return_magic(new_node, buffer, file, corewar) == -1)
        return 84;
    if (*head == NULL) {
        *head = new_node;
    } else {
        current = *head;
        while (current->next != NULL)
            current = current->next;
        new_node->prev = current;
        current->next = new_node;
        new_node->next = NULL;
        current = new_node;
    }
    return 0;
}
