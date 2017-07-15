/*
** socket.h for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/utils
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:05:21 2017 Dylan Deu
** Last update Mon Jun 26 15:05:22 2017 Dylan Deu
*/

#ifndef PSU_2016_ZAPPY_SOCKET_H
#define PSU_2016_ZAPPY_SOCKET_H

#include	<netdb.h>
#include	<arpa/inet.h>
#include	"game/game.h"

int		create_socket(const char * const protoname);
bool		socket_bind(const int sock,
				const in_addr_t addr,
				const unsigned short port,
				t_game *game);
bool		socket_listen(const int sock,
				  const int limit);
int		accept_connection(t_game *game);

#endif /* !PSU_2016_ZAPPY_SOCKET_H_ */
