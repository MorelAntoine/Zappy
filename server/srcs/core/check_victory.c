/*
** check_victory.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Tue Jun 27 15:21:47 2017 Dylan Deu
** Last update Tue Jun 27 15:21:47 2017 Dylan Deu
*/

#include	"game/team.h"
#include	"utils/send.h"
#include	"game/game.h"


#include <stdio.h>

bool		check_victory(t_game *game)
{
  t_team	*team;

  team = list_get_first(game->teams);
  while (team)
  {
    if (team->max_level >= 8 && team->nb_player_max_level >= 6)
    {
      if (game->graph_client > 0)
	my_send(game->graph_client, "seg %s\n", team->name);
      return (true);
    }
    team = list_get_next(game->teams);
  }
  return (false);
}
