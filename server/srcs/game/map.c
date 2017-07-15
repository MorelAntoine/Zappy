/*
** map.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:52:01 2017 Dylan Deu
** Last update Mon Jun 26 14:52:01 2017 Dylan Deu
*/

#include	<stdlib.h>
#include	"game/map.h"

t_map		*map_init(unsigned int h, unsigned w)
{
  t_map		*map;
  unsigned int	index;

  map = malloc(sizeof(t_map));
  if (!map)
    return (NULL);
  map->height = h;
  map->width = w;
  map->content = malloc(sizeof(t_box *) * w * h);
  if (!map->content)
    {
      free(map);
      return (NULL);
    }
  index = 0;
  while (index < h * w)
    {
      map->content[index] = box_init();
      if (!map->content[index])
	return (NULL);
      index++;
    }
  return (map);
}

void		map_delete(t_map *map)
{
  unsigned int	index;

  if (!map)
    return ;
  index = 0;
  while (map->content && index < map->height * map->width)
    {
      box_delete(map->content[index]);
      index++;
    }
  if (map->content)
    free(map->content);
  free(map);
}
