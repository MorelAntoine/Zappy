/*
** plv.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:53:52 2017 Dylan Deu
** Last update Mon Jun 26 14:53:52 2017 Dylan Deu
*/

#include	<stdio.h>
#include	"utils/send.h"
#include	"utils/nbr.h"
#include	"graphic_actions/actions.h"
#include	"game/client.h"

bool	plv(t_game *game, char *line)
{
  t_client	*client;
  unsigned int	n;

  if (!is_pos_num(line))
    {
      my_send(game->graph_client, "sbp\n");
      return (true);
    }
  n = atoi(line);
  client = list_get_first(game->clients);
  while (client)
    {
      if (client->id == n && client->team)
	{
	  my_send(game->graph_client, "ppo %u %u\n", n, client->level);
	  return (true);
	}
      client = list_get_next(game->clients);
    }
  my_send(game->graph_client, "sbp\n");
  return (true);
}
