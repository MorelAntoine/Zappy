/*
** stone_list.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:52:49 2017 Dylan Deu
** Last update Mon Jun 26 14:52:49 2017 Dylan Deu
*/

#include	<stdlib.h>
#include	"game/stone_list.h"

t_stone_list	*stone_list_create(void)
{
  t_stone_list	*list;

  list = malloc(sizeof(t_stone_list));
  if (!list)
    return (NULL);
  list->linemate = 0;
  list->deraumere = 0;
  list->sibur = 0;
  list->mendiane = 0;
  list->phiras = 0;
  list->thystame = 0;
  return (list);
}

void		stone_list_delete(t_stone_list *list)
{
  free(list);
}
