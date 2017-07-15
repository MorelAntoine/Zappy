/*
** send_eject.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Sun Jul 02 19:59:37 2017 Dylan Deu
** Last update Sun Jul 02 19:59:37 2017 Dylan Deu
*/

#include	"utils/send.h"
#include	"game/client.h"

void		send_eject(t_game *game, t_client *client, t_client *it)
{
  if (it->disconnect == false)
    my_send(it->fd, "eject: %d\n", (client->pos_orientation + 1) % 4 + 1);
  my_send(game->graph_client, "ppo %u %u %u %d\n",
	  it->id, it->pos_x,
	  it->pos_y, it->pos_orientation);
}
