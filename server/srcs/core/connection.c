/*
** connection.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Thu Jun 15 14:57:27 2017 Dylan Deu
** Last update Thu Jun 15 14:57:27 2017 Dylan Deu
*/

#include		<stdio.h>
#include		<unistd.h>
#include		<netinet/in.h>
#include		"utils/socket.h"

bool			init_connection(t_game *game, int port)
{
  int			nbTeams;

  nbTeams = (int)(list_size(game->teams));
  game->fd = create_socket("TCP");
  if (game->fd == -1)
  {
    perror("initialize : create_socket()");
    return (false);
  }
  if (!socket_bind(game->fd, INADDR_ANY, htons(port), game))
  {
    perror("initialize : socket_bind()");
    close(game->fd);
    return (false);
  }
  if (!socket_listen(game->fd, (game->max_players_team * nbTeams) + 1))
  {
    perror("initialize : socket_listen()");
    close(game->fd);
    return (false);
  }
  return (true);
}
