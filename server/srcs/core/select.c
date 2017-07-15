/*
** select.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Thu Jun 15 13:28:56 2017 Dylan Deu
** Last update Thu Jun 15 13:28:56 2017 Dylan Deu
*/

#include		<stdio.h>
#include		<fcntl.h>
#include		<unistd.h>
#include		<errno.h>
#include		"game/client.h"
#include		"core/core.h"

static void		close_graph_client(t_game *game)
{
  close(game->graph_client);
  game->graph_client = -1;
}

static bool		find_select_error(t_game *game)
{
  t_client		*client;

  client = list_get_first(game->clients);
  if (errno == EBADF)
  {
    if (fcntl(game->graph_client, F_GETFD) < 0)
      close_graph_client(game);
    while (client)
    {
      if (fcntl(game->graph_client, F_GETFD) < 0)
      {
	client_delete(client, false);
	list_delete_node(game->clients, client, false);
      }
      client = list_get_next(game->clients);
    }
  }
  else if (errno == EINVAL)
  {
    if (game->fd < 0)
      return (false);
  }
  return (true);
}

int			make_select(t_game *game, fd_set *fd_read)
{
  struct timeval	time;
  int			max_fd;

  max_fd = get_max_fd(game, fd_read);
  time.tv_usec = 1;
  time.tv_sec = 0;
  if (select(max_fd + 1, fd_read, NULL, NULL, &time) == -1)
  {
    if (find_select_error(game) == false)
      return (-2);
    return (-1);
  }
  return (0);
}
