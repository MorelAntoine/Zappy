/*
** forward.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:49:08 2017 Dylan Deu
** Last update Mon Jun 26 14:49:08 2017 Dylan Deu
*/

#include	<stdio.h>
#include	"utils/send.h"
#include	"player_actions/forward.h"

static bool	go_left(t_game *game, t_client *client)
{
  client->pos_x = client->pos_x ? (client->pos_x - 1) : (game->map->width - 1);
  return (true);
}


static bool	go_right(t_game *game, t_client *client)
{
  client->pos_x = (client->pos_x + 1) % game->map->width;
  return (true);
}

static bool	go_top(t_game *game, t_client *client)
{
  client->pos_y = client->pos_y ? (client->pos_y - 1) : (game->map->height - 1);
  return (true);
}

static bool	go_bottom(t_game *game, t_client *client)
{
  client->pos_y = (client->pos_y + 1) % game->map->height;
  return (true);
}

bool		forward(t_game *game, t_client *client, char *line)
{
  if (!client_is_auth(client))
    return (true);
  (void)line;
  if (g_go[client->pos_orientation](game, client))
    {
      if (client->disconnect == false)
	my_send(client->fd, "ok\n");
      if (game->graph_client != -1)
	my_send(game->graph_client, "ppo %u %u %u %d\n",
		client->id, client->pos_x,
		client->pos_y, client->pos_orientation);
      return (true);
    }
  return (false);
}
