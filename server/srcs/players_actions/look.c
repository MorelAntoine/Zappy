/*
** look.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:54:58 2017 Dylan Deu
** Last update Mon Jun 26 14:54:58 2017 Dylan Deu
*/

#include	<string.h>
#include	<stdio.h>
#include	"core/core.h"
#include	"player_actions/actions.h"
#include	"player_actions/look.h"

static void	check_case(t_game *game, int y, int x, unsigned int *results)
{
  t_box		*box;

  box = game->map->content[y * game->map->width + x];
  results[0] = box->food;
  results[1] = box->stones->linemate;
  results[2] = box->stones->deraumere;
  results[3] = box->stones->sibur;
  results[4] = box->stones->mendiane;
  results[5] = box->stones->phiras;
  results[6] = box->stones->thystame;
}

static char	*get_from_case_player(t_game *game, unsigned int y,
				     unsigned int x, char *result)
{
  t_client	*client;
  char		*tmp;

  client = list_get_first(game->clients);
  while (client)
    {
      if (client->pos_y == y && client->pos_x == x)
	{
	  tmp = result;
	  asprintf(&result, "%s%splayer", strlen(tmp) ? tmp : "",
		   strlen(tmp) ? " " : "");
	  free(tmp);
	}
      client = list_get_next(game->clients);
    }
  return (result);
}

static char	*get_from_case(t_game *game, int y, int x)
{
  unsigned int	results[7];
  char		*result;
  char		*tmp;
  unsigned int	index[2];

  check_case(game, y, x, results);
  result = strdup("");
  index[0] = 0;
  while (index[0] < 7)
    {
      index[1] = 0;
      while (index[1] < results[index[0]])
	{
	  tmp = result;
	  asprintf(&result, "%s%s%s", strlen(tmp) ? tmp : "",
		   strlen(tmp) ? " " : "", g_lt_rs[index[0]]);
	  free(tmp);
	  index[1] += 1;
	}
      index[0] += 1;
    }
  result = get_from_case_player(game, y, x, result);
  return (result);
}

char		*get_case(t_game *game, t_client *client, int ft, int left)
{
  int		y;
  int		x;

  if (client->pos_orientation == ORIENTATION_NORTH)
    {
      y = (client->pos_y + game->map->height - ft) % game->map->height;
      x = (client->pos_x + game->map->width - ft + left) % game->map->width;
    }
  else if (client->pos_orientation == ORIENTATION_SOUTH)
    {
      y = (client->pos_y + game->map->height + ft) % game->map->height;
      x = (client->pos_x + game->map->width + ft - left) % game->map->width;
    }
  else if (client->pos_orientation == ORIENTATION_EST)
    {
      y = (client->pos_y + game->map->height - ft + left) % game->map->height;
      x = (client->pos_x + game->map->width + left) % game->map->width;
    }
  else
    {
      y = (client->pos_y + game->map->height + ft - left)
	% game->map->height;
      x = (client->pos_x + game->map->width - left) % game->map->width;
    }
  return (get_from_case(game, y, x));
}

bool		look(t_game *game, t_client *client, char *line)
{
  char	*result;
  char	*tmp;

  (void)line;
  tmp = get_case(game, client, 0, 0);
  asprintf(&result, "%s", tmp);
  free(tmp);
  exec_look(game, client, result);
  return (true);
}
