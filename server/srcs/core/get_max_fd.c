/*
** get_max_fd.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Thu Jun 15 11:31:05 2017 Dylan Deu
** Last update Thu Jun 15 11:31:05 2017 Dylan Deu
*/

#include		"game/client.h"

#include <stdio.h>

int			get_max_fd(t_game *game, fd_set *fd_read)
{
  int			fd;
  t_client		*client;

  fd = game->fd;
  FD_ZERO(fd_read);
  FD_SET(game->fd, fd_read);
  if (game->graph_client > 0)
  {
    if (game->graph_client > fd)
      fd = game->graph_client;
    FD_SET(game->graph_client, fd_read);
  }
  client = list_get_first(game->clients);
  while (client)
  {
    if (client->fd > 0)
    {
      FD_SET(client->fd, fd_read);
      if (client->fd > fd)
	fd = client->fd;
    }
    client = list_get_next(game->clients);
  }
  return (fd);
}
