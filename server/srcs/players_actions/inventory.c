/*
** inventory.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:54:51 2017 Dylan Deu
** Last update Mon Jun 26 14:54:51 2017 Dylan Deu
*/

#include	<stdio.h>
#include	<time.h>
#include	"utils/send.h"
#include	"player_actions/actions.h"
#include	"utils/time.h"

bool		inventory(t_game *game, t_client *client, char *line)
{
  unsigned long long int	time;
  unsigned long long int	food;

  (void)line;
  (void)game;
  time = get_time();
  food = (client->time_death < time) ? 0 :
    (client->time_death - time);
  food = (unsigned int)((float)(food) / 1000000 * game->f / 126);
  if (client->disconnect == false)
    my_send(client->fd, "linemate %d, sibur %d, deraumere %u, mendiane %u,"
	      " phiras %u, thystame %u, food %llu\n",
	    client->stones->linemate, client->stones->sibur,
	  client->stones->deraumere, client->stones->mendiane,
	  client->stones->phiras, client->stones->thystame, food);
  return (true);
}
