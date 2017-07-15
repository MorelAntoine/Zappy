/*
** core.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Thu Jun 15 11:24:36 2017 Dylan Deu
** Last update Thu Jun 15 11:24:36 2017 Dylan Deu
*/

#include		<stdio.h>
#include		<unistd.h>
#include		<signal.h>
#include		"game/client.h"
#include		"core/core.h"
#include		"utils/socket.h"

bool			g_loop;

void			sighandler(int sig)
{
  if (sig == SIGINT)
    g_loop = false;
}

static void		run_client(t_game *game, fd_set *fd_read)
{
  t_client		*client;
  t_list_node		*save_client;

  client = list_get_first(game->clients);
  while (client)
  {
    save_client = game->clients->it;
    if (FD_ISSET(client->fd, fd_read))
    {
      if (get_client_cmd(game, client) == false)
	client = list_get_first(game->clients);
      else
	game->clients->it = save_client;
    }
    client = list_get_next(game->clients);
  }
}

static int		run(t_game *game, fd_set *fd_read)
{
  int			fd;

  if (FD_ISSET(game->fd, fd_read))
  {
    fd = accept_connection(game);
    if (fd != -1)
      if (add_new_client(game, fd) == false)
	close(fd);
  }
  if (FD_ISSET(game->graph_client, fd_read))
    get_graphical_cmd(game);
  run_client(game, fd_read);
  return (0);
}

int			core(t_game *game)
{
  int			value;
  fd_set		fd_read;

  g_loop = true;
  signal(SIGINT, sighandler);
  while (g_loop)
  {
    check_death(game);
    check_level(game);
    check_eggs(game);
    check_actions(game);
    check_generate(game);
    if (check_victory(game) == true)
      clean_game(game);
    value = make_select(game, &fd_read);
    if (value == -2)
      g_loop = false;
    else if (value != -1)
      run(game, &fd_read);
  }
  return (0);
}
