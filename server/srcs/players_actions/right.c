/*
** right.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:55:01 2017 Dylan Deu
** Last update Mon Jun 26 14:55:01 2017 Dylan Deu
*/

#include	<stdio.h>
#include	"utils/send.h"
#include	"player_actions/right.h"

static bool	turn_left(t_client *client)
{
  client->pos_orientation = ORIENTATION_WEST;
  return (true);
}


static bool	turn_right(t_client *client)
{
  client->pos_orientation = ORIENTATION_EST;
  return (true);
}

static bool	turn_top(t_client *client)
{
  client->pos_orientation = ORIENTATION_NORTH;
  return (true);
}

static bool	turn_bottom(t_client *client)
{
  client->pos_orientation = ORIENTATION_SOUTH;
  return (true);
}

bool		right(t_game *game, t_client *client, char *line)
{
  if (!client_is_auth(client))
    return (true);
  (void)line;
  (void)game;
  if (g_turn[client->pos_orientation](client))
    {
      if (client->disconnect == false)
	my_send(client->fd, "ok\n");
      if (game->graph_client > 0)
	my_send(game->graph_client, "ppo %u %u %u %d\n",
		client->id, client->pos_x,
		client->pos_y, client->pos_orientation);
      return (true);
    }
  return (false);
}
