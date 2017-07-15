/*
** box.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:51:37 2017 Dylan Deu
** Last update Mon Jun 26 14:51:37 2017 Dylan Deu
*/

#include	<stdlib.h>
#include	"game/box.h"

t_box		*box_init(void)
{
  t_box		*box;

  box = malloc(sizeof(t_box));
  if (!box)
    return (NULL);
  box->stones = stone_list_create();
  if (!box->stones)
    {
      free(box);
      return (NULL);
    }
  box->food = 0;
  return (box);
}

void		box_delete(t_box *box)
{
  if (!box)
    return ;
  if (box->stones)
    stone_list_delete(box->stones);
  free(box);
}
