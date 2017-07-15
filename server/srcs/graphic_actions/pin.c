/*
** pin.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:53:50 2017 Dylan Deu
** Last update Mon Jun 26 14:53:50 2017 Dylan Deu
*/

#include	<stdio.h>
#include	<time.h>
#include	"utils/send.h"
#include	"graphic_actions/actions.h"
#include	"utils/nbr.h"
#include	"utils/time.h"
#include	"game/client.h"

static bool	pin_send(t_game *game, t_client *client)
{
  unsigned long long int	food;

  food = (client->time_death < get_time() / 1000) ? 0 :
	 (client->time_death - get_time());
  food = (unsigned int)((float)(food) / 1E6 * game->f / 126);
  my_send(game->graph_client, "pin %u %u %u %llu %u %u %u %u %u %u\n",
	  client->id, client->pos_x,
	  client->pos_y, food, client->stones->linemate,
	  client->stones->deraumere, client->stones->sibur,
	  client->stones->mendiane,
	  client->stones->phiras, client->stones->thystame);
  return (true);
}

bool	pin(t_game *game, char *line)
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
	  pin_send(game, client);
	  return (true);
	}
      client = list_get_next(game->clients);
    }
  my_send(game->graph_client, "sbp\n");
  return (true);
}
