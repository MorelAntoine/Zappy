/*
** accept_connection.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Thu Jun 15 16:20:54 2017 Dylan Deu
** Last update Thu Jun 15 16:20:54 2017 Dylan Deu
*/

#include		<netinet/in.h>
#include		<arpa/inet.h>
#include		"game/game.h"

#include <stdio.h>

int			accept_connection(t_game *game)
{
  int			fd;
  char			*ip;
  struct sockaddr_in	cin;
  socklen_t		socklen;

  socklen = sizeof((cin));
  fd = accept(game->fd, (struct sockaddr *)(&cin), &socklen);
  if (fd == -1)
    return (-1);
  ip = inet_ntoa(cin.sin_addr);
  printf("Connection from : %s\n", ip);
  return (fd);
}
