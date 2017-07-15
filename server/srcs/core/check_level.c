/*
** check_level.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed Jun 28 14:57:33 2017 Dylan Deu
** Last update Wed Jun 28 14:57:33 2017 Dylan Deu
*/

#include		"game/client.h"

static void		get_player_max_level(t_game *game, t_team *team,
						unsigned int max_level)
{
  unsigned int		player;
  t_client		*client;

  player = 0;
  client = list_get_first(game->clients);
  while (client)
  {
    if (client->team == team && client->level == max_level)
      player += 1;
    client = list_get_next(game->clients);
  }
  team->max_level = max_level;
  team->nb_player_max_level = player;
}

void			check_level(t_game *game)
{
  unsigned int		max_level;
  t_team		*team;
  t_client		*client;

  max_level = 1;
  team = list_get_first(game->teams);
  while (team)
  {
    if (team->nb_player_max_level <= 0 && team->max_level > 1)
    {
      client = list_get_first(game->clients);
      while (client)
      {
	if (client->team == team && client->level > max_level)
	  max_level = client->level;
	client = list_get_next(game->clients);
      }
      get_player_max_level(game, team, max_level);
    }
    team = list_get_next(game->teams);
  }
}
