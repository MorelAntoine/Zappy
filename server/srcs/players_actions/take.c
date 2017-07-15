/*
** take.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:55:10 2017 Dylan Deu
** Last update Mon Jun 26 14:55:10 2017 Dylan Deu
*/

#include	<string.h>
#include	<stdio.h>
#include	<time.h>
#include	"utils/send.h"
#include	"player_actions/take.h"

bool		take_food(t_game *game, t_client *client)
{
  if (!game->map->content[client->pos_y * game->map->width
			  + client->pos_x]->food)
    return (false);
  game->map->content[client->pos_y * game->map->width
		     + client->pos_x]->food -= 1;
  client->time_death += 126000000 / game->f;
  if (game->graph_client != -1)
    my_send(game->graph_client, "pgt %u 0\n", client->id);
  return (true);
}

bool		take_linemate(t_game *game, t_client *client)
{
  if (!game->map->content[client->pos_y * game->map->width
			  + client->pos_x]->stones->linemate)
    return (false);
  game->map->content[client->pos_y * game->map->width
		     + client->pos_x]->stones->linemate -= 1;
  client->stones->linemate += 1;
  if (game->graph_client != -1)
    my_send(game->graph_client, "pgt %u 1\n", client->id);
  return (true);
}

bool		take_deraumere(t_game *game, t_client *client)
{
  if (!game->map->content[client->pos_y * game->map->width
			  + client->pos_x]->stones->deraumere)
    return (false);
  game->map->content[client->pos_y * game->map->width
		     + client->pos_x]->stones->deraumere -= 1;
  client->stones->deraumere += 1;
  if (game->graph_client != -1)
    my_send(game->graph_client, "pgt %u 2\n", client->id);
  return (true);
}

bool		take_send(t_game *game, t_client *client)
{
  t_box			*box;
  unsigned int		food;
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

bool		take(t_game *game, t_client *client, char *line)
{
  unsigned int	index;
  char		*object;

  (void)g_list_actions;
  if (!line || strlen(line) == 0)
    {
      if (client->disconnect == false)
	my_send(client->fd, "ko\n");
      return (true);
    }
  object = strtok(line, " ");
  index = 0;
  while (index < sizeof(g_list_objects) / sizeof(char *))
    {
      if (take_treat(game, client, object, index) == true)
	return (true);
      index++;
    }
  if (client->disconnect == false)
    my_send(client->fd, "ko\n");
  return (true);
}
