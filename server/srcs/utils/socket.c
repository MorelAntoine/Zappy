/*
** create_socket.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Thu Jun 15 14:59:05 2017 Dylan Deu
** Last update Thu Jun 15 14:59:05 2017 Dylan Deu
*/

#include		"utils/socket.h"

int			create_socket(const char * const protoname)
{
  int			sock;
  struct protoent	*pe;

  pe = getprotobyname(protoname);
  if (!pe)
    return (-1);
  sock = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (sock == -1)
    return (-1);
  return (sock);
}

bool			socket_bind(const int sock,
					const in_addr_t addr,
					const unsigned short port,
					t_game *game)
{
  int			opt;
  struct sockaddr_in	sin;

  opt = 1;
  sin.sin_addr.s_addr = addr;
  sin.sin_family = AF_INET;
  sin.sin_port = port;
  setsockopt(game->fd, SOL_SOCKET, (SO_REUSEPORT | SO_REUSEADDR | SO_ERROR),
	     (char *)(&opt), sizeof(opt));
  if (bind(sock, (const struct sockaddr *)(&sin),
	   sizeof(sin)) == -1)
    return (false);
  game->ip = inet_ntoa(sin.sin_addr);
  return (true);
}

bool			socket_listen(const int sock,
					  const int limit)
{
  if (listen(sock, limit) == -1)
    return (false);
  return (true);
}
