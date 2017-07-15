/*
** broadcast.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:54:22 2017 Dylan Deu
** Last update Mon Jun 26 14:54:22 2017 Dylan Deu
*/

#include	<stdio.h>
#include	"utils/send.h"
#include	"player_actions/actions.h"

static unsigned int	pw2(int l)
{
  return ((unsigned int)(l * l));
}

static bool	send_broad_from(t_client *to, int size[2], char *line)
{
  int	dir;

  if (size[0] == 0 && size[1] < 0)
    dir = 5;
  else if (size[0] == 0)
    dir = 1;
  else if (size[1] == 0 && size[0] < 0)
    dir = 3;
  else if (size[1] == 0)
    dir = 7;
  else if (size[0] > 0 && size[1] > 0)
    dir = 6;
  else if (size[0] < 0 && size[1] < 0)
    dir = 2;
  else if (size[0] > 0)
    dir = 4;
  else
    dir = 8;
  dir += 8;
  dir -= (8 - ((to->pos_orientation - 1) * 2));
  dir = (dir - 1) % 8 + 1;
  if (to->disconnect == false)
    my_send(to->fd, "message %d, %s\n", dir, line);
  return (true);
}

static bool	send_broad(t_game *game, t_client *from,
			      t_client *to, char *line)
{
  int	size[3][2];

  size[0][0] = from->pos_y - to->pos_y;
  size[0][1] = from->pos_x - to->pos_x;
  size[1][0] = (from->pos_y < to->pos_y) ? (from->pos_y + game->map->height
		 - to->pos_y) :
	       (from->pos_y - (to->pos_y + game->map->height));
  size[1][1] = from->pos_x - to->pos_x;
  size[2][0] = from->pos_y - to->pos_y;
  size[2][1] = (from->pos_x < to->pos_x) ? (from->pos_x + game->map->width -
	    to->pos_x) : (from->pos_x - (to->pos_x + game->map->width));
  if (pw2(size[0][0]) + pw2(size[0][1]) < pw2(size[1][0]) + pw2(size[1][1])
      && pw2(size[0][0]) + pw2(size[0][1]) <
		 pw2(size[2][0]) + pw2(size[2][1]))
    send_broad_from(to, size[0], line);
  else if (pw2(size[1][0]) + pw2(size[1][1]) <
    pw2(size[2][0]) + pw2(size[2][1]))
    send_broad_from(to, size[1], line);
  else
    send_broad_from(to, size[2], line);
  return (true);
}

bool	broadcast_text(t_game *game, t_client *client, char *line)
{
  t_client	*it;

  it = list_get_first(game->clients);
  while (it)
    {
      if (it != client)
	{
	  if (it->pos_y == client->pos_y &&
	      it->pos_x == client->pos_x && it->disconnect == false)
	    my_send(it->fd, "message 0, %s\n", line);
	  else
	    send_broad(game, client, it, line);
	}
      it = list_get_next(game->clients);
    }
  if (game->graph_client != -1)
    my_send(game->graph_client, "pbc %u %s\n", client->id, line);
  if (client->disconnect == false)
    my_send(client->fd, "ok\n");
  return (true);
}
