/*
** eject.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:54:38 2017 Dylan Deu
** Last update Mon Jun 26 14:54:38 2017 Dylan Deu
*/

#include	<stdio.h>
#include	"utils/send.h"
#include	"player_actions/eject.h"

static bool	a_up(t_game *game, t_client *client)
{
  client->pos_y = (client->pos_y + game->map->height - 1) % game->map->height;
  return (true);
}
static bool	a_left(t_game *game, t_client *client)
{
  client->pos_x = (client->pos_x + game->map->width - 1) % game->map->width;
  return (true);
}
static bool	a_down(t_game *game, t_client *client)
{
  client->pos_y = (client->pos_y + 1) % game->map->height;
  return (true);
}

static bool	a_right(t_game *game, t_client *client)
{
  client->pos_x = (client->pos_x + 1) % game->map->width;
  return (true);
}

bool		eject(t_game *game, t_client *client, char *toto)
{
  t_client	*it;
  bool		f;

  (void)toto;
  my_send(game->graph_client, "pex %u\n", client->id);
  it = list_get_first(game->clients);
  f = false;
  while (it)
    {
      if (client != it && client->pos_x == it->pos_x
	  && client->pos_y == it->pos_y)
	{
	  f = true;
	  g_list_actions[client->pos_orientation](game, it);
	  send_eject(game, client, it);
	}
      it = list_get_next(game->clients);
    }
  if (f)
    return (my_send(client->fd, "ok\n") ? true : true);
  if (client->disconnect == false)
    my_send(client->fd, "ko\n");
  return (true);
}
