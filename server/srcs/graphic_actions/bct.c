/*
** bct.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:52:59 2017 Dylan Deu
** Last update Mon Jun 26 14:52:59 2017 Dylan Deu
*/

#include	<stdio.h>
#include	<string.h>
#include	"utils/send.h"
#include	"graphic_actions/actions.h"
#include	"utils/nbr.h"

static bool	bct_error(t_game *game)
{
  my_send(game->graph_client, "sbp\n");
  return (true);
}

bool	bct_case(t_game *game, int y, int x)
{
  t_box		*box;

  box = game->map->content[y * game->map->width + x];
  my_send(game->graph_client, "bct %u %u %u %u %u %u %u %u %u\n",
	  x, y, box->food, box->stones->linemate, box->stones->deraumere,
	  box->stones->sibur, box->stones->mendiane,
	  box->stones->phiras, box->stones->thystame);
  return (true);
}

bool	bct(t_game *game, char *line)
{
  unsigned int	y;
  unsigned int	x;

  strtok(line, " ");
  if (!is_pos_num(line))
    return (bct_error(game));
  x = atoi(line);
  line = strtok(NULL, " ");
  if (!is_pos_num(line))
    return (bct_error(game));
  y = atoi(line);
  if (y >= game->map->height || x >= game->map->width)
    return (bct_error(game));
  return (bct_case(game, y, x));
}
