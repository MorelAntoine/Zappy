/*
** close_client.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 15:58:05 2017 Dylan Deu
** Last update Mon Jun 26 15:58:05 2017 Dylan Deu
*/

#include		"player_actions/queue_member.h"

bool			close_client(t_game *game, t_client *client)
{
  (void)game;
  client->disconnect = true;
  return (true);
}
