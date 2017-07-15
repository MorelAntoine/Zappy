/*
** game.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:51:54 2017 Dylan Deu
** Last update Mon Jun 26 14:51:54 2017 Dylan Deu
*/

#include	<string.h>
#include	<stdlib.h>
#include	"utils/time.h"
#include	"game/game.h"
#include	"game/client.h"

t_game		*game_init(unsigned int h, unsigned int w)
{
  t_game	*game;

  game = malloc(sizeof(t_game));
  if (!game)
    return (NULL);
  game->fd = -1;
  game->ip = NULL;
  game->map = map_init(h, w);
  game->clients = list_create();
  game->teams = list_create();
  game->eggs = list_create();
  game->buff = init_buff();
  game->queue = list_create();
  game->regenerate = get_time();
  game->food = get_time();
  game->graph_client = -1;
  if (!game->map || !game->teams || !game->clients)
    {
    game_delete(game);
      return (NULL);
    }
  generate_resources(game);
  return (game);
}

void		game_delete_teams(t_game *game)
{
  t_team	*t;

  if (!game->teams)
    return ;
  t = list_get_first(game->teams);
  while (t)
    {
      team_delete(t);
      t = list_get_next(game->teams);
    }
  list_delete(game->teams, false);
}

void		game_delete(t_game *game)
{
  t_client	*it;

  if (!game)
    return ;
  if (game->map)
    map_delete(game->map);
  game_delete_teams(game);
  if (game->clients)
    {
      it = list_get_first(game->clients);
      while (it)
	{
	  client_delete(it, true);
	  it = list_get_next(game->clients);
	}
      list_delete(game->clients, false);
    }
  if (game->buff)
    free(game->buff);
  if (game->queue)
    list_delete(game->queue, false);
  if (game->eggs)
    list_delete(game->eggs, false);
  free(game);
}

bool		game_add_team(t_game *game, char *team)
{
  t_team	*mteam;

  mteam = team_init(strdup(team), game);
  list_push_back(game->teams, mteam);
  return (true);
}
