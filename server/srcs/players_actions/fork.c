/*
** fork.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:54:42 2017 Dylan Deu
** Last update Mon Jun 26 14:54:42 2017 Dylan Deu
*/

#include	<time.h>
#include	<stdio.h>
#include	"utils/send.h"
#include	"player_actions/actions.h"
#include	"game/egg.h"
#include	"utils/time.h"

static void	set_id(t_game *game, t_egg *egg)
{
  t_egg	*e;
  unsigned int	index;

  e = list_get_first(game->eggs);
  index = 0;
  while (e)
    {
      index = e->id;
      e = list_get_next(game->eggs);
    }
  index += 1;
  egg->id = index;
}

bool	game_fork(t_game *game, t_client *client, char *line)
{
  t_egg			*egg;

  (void)line;
  egg = malloc(sizeof(t_egg));
  if (!egg)
    return (false);
  egg->team = client->team;
  egg->time_death = get_time() + 600000000 / game->f;
  egg->y = client->pos_y;
  egg->x = client->pos_x;
  set_id(game, egg);
  list_push_back(game->eggs, egg);
  if (game->graph_client != -1)
    my_send(game->graph_client, "enw %u %u %u %u\n",
	    egg->id, client->id,
	    egg->x, egg->y);
  if (client->disconnect == false)
    my_send(client->fd, "ok\n");
  return (true);
}

bool	start_fork(t_game *game, t_client *client)
{
  if (game->graph_client != -1)
    my_send(game->graph_client, "pfk %u\n", client->id);
  return (true);
}

bool	death_egg(t_game *game, t_egg *egg)
{
  if (game->graph_client != -1)
    my_send(game->graph_client, "edi %u\n", egg->id);
  list_delete_node(game->eggs, egg, true);
  return (true);
}

bool	birth_client_from_egg(t_game *game, t_egg *egg, t_client *client)
{
  client->pos_x = egg->x;
  client->pos_y = egg->y;
  client->team = egg->team;
  if (game->graph_client != -1)
    my_send(game->graph_client, "eht %u\n", egg->id);
  list_delete_node(game->eggs, egg, true);
  return (true);
}
