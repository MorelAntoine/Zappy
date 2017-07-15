/*
** look_part_two.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Sat Jul 01 18:27:08 2017 Dylan Deu
** Last update Sat Jul 01 18:27:08 2017 Dylan Deu
*/

#include	<stdio.h>
#include	"utils/send.h"
#include	"core/core.h"

void		exec_look(t_game *game, t_client *client, char *result)
{
  char		*tmp;
  char		*t;
  int		index_front;
  int		index_left;

  index_front = 1;
  while (index_front <= (int)(client->level))
  {
    index_left = 0;
    while (index_left < index_front * 2 + 1)
    {
      tmp = result;
      t = get_case(game, client, index_front, index_left);
      asprintf(&result, "%s%s%s", tmp, ",", t);
      free(t);
      free(tmp);
      index_left++;
    }
    index_front++;
  }
  if (client->disconnect == false)
    my_send(client->fd, "[ %s ]\n", result);
  free(result);
}
