/*
** tna.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:54:03 2017 Dylan Deu
** Last update Mon Jun 26 14:54:03 2017 Dylan Deu
*/

#include	<stdio.h>
#include	"utils/send.h"
#include	"graphic_actions/actions.h"

bool	tna(t_game *game, char *line)
{
  char	*tmp;

  (void)line;
  tmp = list_get_first(game->teams);
  while (tmp)
    {
      my_send(game->graph_client, "tna %s\n", tmp);
      tmp = list_get_next(game->teams);
    }
  return (true);
}
