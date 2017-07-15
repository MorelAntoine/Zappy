/*
** add_team.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 16:09:36 2017 Dylan Deu
** Last update Mon Jun 26 16:09:36 2017 Dylan Deu
*/

#include	<string.h>
#include	"utils/send.h"
#include	"utils/time.h"
#include	"game/client.h"

static void	send_graph_response(t_game *game, t_client *client)
{
  if (game->graph_client > 0)
    my_send(game->graph_client, "pnw %u %u %u %d %u %s\n", client->id,
	    client->pos_x, client->pos_y, client->pos_orientation,
	    client->level, client->team->name);
}

bool		add_team(t_game *game, t_client *client, char *token)
{
  t_team	*team;

  team = list_get_first(game->teams);
  while (team)
  {
    if (strcmp(team->name, token) == 0)
    {
      team->nb_players += 1;
      if (team->nb_players > game->max_players_team)
	return (false);
      client->time_death = get_time() + (1260000000 / game->f);
      if (client->disconnect == false)
	my_send(client->fd, "%d\n%d %d\n",
		game->max_players_team - team->nb_players,
	      game->map->width, game->map->height);
      client->team = team;
      send_graph_response(game, client);
      break;
    }
    team = list_get_next(game->teams);
  }
  if (client->team == NULL && client->disconnect == false)
    my_send(client->fd, "ko\n");
  return (true);
}
