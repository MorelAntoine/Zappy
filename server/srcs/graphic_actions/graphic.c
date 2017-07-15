/*
** graphic.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:53:39 2017 Dylan Deu
** Last update Mon Jun 26 14:53:39 2017 Dylan Deu
*/

#include	<stdio.h>
#include	<unistd.h>
#include	"utils/send.h"
#include	"graphic_actions/actions.h"
#include	"game/client.h"

static bool	graphic_map(t_game *game)
{
  unsigned int	y;
  unsigned int	x;
  t_box		*box;

  y = 0;
  while (y < game->map->height)
    {
      x = 0;
      while (x < game->map->width)
      {
	box = game->map->content[y * game->map->width + x];
	my_send(game->graph_client, "bct %u %u %u %u %u %u %u %u %u\n",
		x, y, box->food, box->stones->linemate, box->stones->deraumere,
		box->stones->sibur, box->stones->mendiane,
		box->stones->phiras, box->stones->thystame);
	x++;
      }
      y++;
    }
  return (true);
}

static bool	graphic_teams(t_game *game)
{
  t_team	*team;

  team = list_get_first(game->teams);
  while (team)
    {
      my_send(game->graph_client, "tna %s\n", team->name);
      team = list_get_next(game->teams);
    }
  return (true);
}

static bool	graphic_players(t_game *game)
{
  t_client	*client;

  client = list_get_first(game->clients);
  while (client)
    {
      if (client->team != NULL)
	my_send(game->graph_client, "pnw %u %u %u %d %u %s\n",
		client->id, client->pos_x,
	      client->pos_y, client->pos_orientation,
	      client->level, client->team->name);
      client = list_get_next(game->clients);
    }
  return (true);
}

void			close_graphic(t_game *game)
{
  close(game->graph_client);
  game->graph_client = -1;
}

bool	graphic(t_game *game, char *line)
{
  (void)line;
  my_send(game->graph_client, "msz %u %u\n",
	  game->map->width, game->map->height);
  my_send(game->graph_client, "sgt %u\n",
	  game->f);
  graphic_map(game);
  graphic_teams(game);
  graphic_players(game);
  return (true);
}
