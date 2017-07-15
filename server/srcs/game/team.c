/*
** team.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:52:54 2017 Dylan Deu
** Last update Mon Jun 26 14:52:54 2017 Dylan Deu
*/

#include	<stdlib.h>
#include	"game/team.h"
#include	"game/game.h"

t_team		*team_init(char *name, t_game *game)
{
  t_team	*team;

  team = malloc(sizeof(t_team));
  if (!team)
    return (NULL);
  team->name = name;
  team->max_level = 1;
  team->nb_players = 0;
  team->nb_player_max_level = 0;
  team->max_clients = game->max_players_team;
  return (team);
}

void	team_delete(t_team *team)
{
  if (!team)
    return ;
  if (team->name)
    free(team->name);
  free(team);
}
