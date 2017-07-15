/*
** sst.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:54:00 2017 Dylan Deu
** Last update Mon Jun 26 14:54:00 2017 Dylan Deu
*/

#include	<stdio.h>
#include	"utils/send.h"
#include	"graphic_actions/actions.h"
#include	"utils/nbr.h"

bool	sst(t_game *game, char *line)
{
  (void)line;
  if (!is_pos_num(line))
    {
      my_send(game->graph_client, "ko\n");
      return (true);
    }
  game->f = atoi(line);
  my_send(game->graph_client, "sgt %u\n", game->f);
  return (true);
}
