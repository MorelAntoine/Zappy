/*
** resources.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:52:12 2017 Dylan Deu
** Last update Mon Jun 26 14:52:12 2017 Dylan Deu
*/

#include	<time.h>
#include	"game/game.h"

bool		generate_resources_case(t_box *box)
{
  unsigned int	result;

  box->food += rand() % 10;
  result = rand() % 5;
  if (result == 0)
    box->stones->linemate += 1;
  result = rand() % 5;
  if (result == 0)
    box->stones->deraumere += 1;
  result = rand() % 5;
  if (result == 0)
    box->stones->sibur += 1;
  result = rand() % 5;
  if (result == 0)
    box->stones->mendiane += 1;
  result = rand() % 5;
  if (result == 0)
    box->stones->phiras += 1;
  result = rand() % 5;
  if (result == 0)
    box->stones->thystame += 1;
  return (true);
}

bool	generate_resources(t_game *game)
{
  unsigned int		y;
  unsigned int		x;
  struct timespec	ts;

  clock_gettime(CLOCK_MONOTONIC, &ts);
  srand((time_t)ts.tv_nsec);
  y = 0;
  while (y < game->map->height)
    {
      x = 0;
      while (x < game->map->width)
      {
	generate_resources_case(game->map->content[y * game->map->width + x]);
	x++;
      }
      y++;
    }
  return (true);
}
