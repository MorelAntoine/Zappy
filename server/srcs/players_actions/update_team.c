/*
** update_team.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:55:16 2017 Dylan Deu
** Last update Mon Jun 26 14:55:16 2017 Dylan Deu
*/

#include	<string.h>
#include	"game/game.h"
#include	"game/client.h"

bool	update_player_team(t_game *game, t_client *client)
{
  unsigned int	index;
  t_team	*team;

  index = 0;
  team = list_get_first(game->teams);
  while (team)
    {
      if (strcmp(team->name, client->team->name) == 0)
	{
	  if (team->max_level < client->level)
	    {
	      team->max_level = client->level;
	      team->nb_player_max_level = 1;
	    }
	  else if (team->max_level == client->level)
	    team->nb_player_max_level += 1;
	  return (true);
	}
      index++;
      team = list_get_next(game->teams);
    }
  return (false);
}
