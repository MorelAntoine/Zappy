/*
** mct.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:53:43 2017 Dylan Deu
** Last update Mon Jun 26 14:53:43 2017 Dylan Deu
*/

#include	"graphic_actions/actions.h"

bool	mct(t_game *game, char *line)
{
  unsigned int	y;
  unsigned int	x;

  (void)line;
  y = 0;
  while (y < game->map->height)
    {
      x = 0;
      while (x < game->map->width)
	{
	  bct_case(game, y, x);
	  x++;
	}
      y++;
    }
  return (true);
}
