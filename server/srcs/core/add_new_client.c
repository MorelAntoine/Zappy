/*
** add_new_client.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Thu Jun 15 16:28:07 2017 Dylan Deu
** Last update Thu Jun 15 16:28:07 2017 Dylan Deu
*/

#include		"game/client.h"

bool			add_new_client(t_game *game, int fd)
{
  if (client_init(fd, game) == NULL)
    return (false);
  return (true);
}
