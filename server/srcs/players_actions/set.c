/*
** set.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:55:04 2017 Dylan Deu
** Last update Tue Jun 27 12:23:31 2017 Dylan Deu
*/

#include	<time.h>
#include	<string.h>
#include	<stdio.h>
#include	"utils/send.h"
#include	"player_actions/set.h"

bool		set_food(t_game *game, t_client *client)
{
  game->map->content[client->pos_y * game->map->width
		     + client->pos_x]->food += 1;
  if (client->time_death < 126000000 / game->f)
    client->time_death = 0;
  else
    client->time_death -= 126000000 / game->f;
  if (game->graph_client != -1)
    my_send(game->graph_client, "pdr %u 0\n", client->id);
  return (true);
}

bool		set_linemate(t_game *game, t_client *client)
{
  if (!client->stones->linemate)
    return (false);
  game->map->content[client->pos_y * game->map->width
		     + client->pos_x]->stones->linemate += 1;
  client->stones->linemate -= 1;
  if (game->graph_client != -1)
    my_send(game->graph_client, "pdr %u 1\n", client->id);
  return (true);
}

bool		set_deraumere(t_game *game, t_client *client)
{
  if (!client->stones->deraumere)
    return (false);
  game->map->content[client->pos_y * game->map->width
		     + client->pos_x]->stones->deraumere += 1;
  client->stones->deraumere -= 1;
  if (game->graph_client != -1)
    my_send(game->graph_client, "pdr %u 2\n", client->id);
  return (true);
}

bool		set_send(t_game *game, t_client *client)
{
  t_box	*box;
  unsigned int          food;
  struct timespec       ts;

  clock_gettime(CLOCK_MONOTONIC, &ts);
  food = (client->time_death < (unsigned int)(ts.tv_nsec) / 1000) ? 0 :
    (client->time_death - ts.tv_nsec);
  food = (unsigned int)((float)(food) / 1000000 * game->f / 126);
  box = game->map->content[client->pos_y * game->map->width + client->pos_x];
  if (client->disconnect == false)
    my_send(client->fd, "ok\n");
  if (game->graph_client != -1)
    my_send(game->graph_client, "pin %u %u %u %u %u %u %u %u %u %u\n"
	    "bct %u %u %u %u %u %u %u %u %u\n",
	    client->id, client->pos_x,
	    client->pos_y, food, client->stones->linemate,
	    client->stones->deraumere, client->stones->sibur,
	    client->stones->mendiane,
	    client->stones->phiras, client->stones->thystame,
	    client->pos_x, client->pos_y, box->food,
	    box->stones->linemate, box->stones->deraumere,
	    box->stones->sibur, box->stones->mendiane,
	    box->stones->phiras, box->stones->thystame);
  return (true);
}

bool		set(t_game *game, t_client *client, char *line)
{
  unsigned int	index;
  char		*object;

  object = strtok(line, " ");
  index = 0;
  while (index < sizeof(g_list_objects) / sizeof(char  *))
    {
      if (strcmp(object, g_list_objects[index]) == 0)
	{
	  if (g_list_actions[index](game, client))
	    set_send(game, client);
	  else
	  {
	    if (client->disconnect == false)
	      my_send(client->fd, "ko\n");
	  }
	  return (true);
	}
      index++;
    }
  if (client->fd == true)
    my_send(client->fd, "ko\n");
  return (true);
}
