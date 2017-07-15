/*
** msz.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:53:47 2017 Dylan Deu
** Last update Mon Jun 26 14:53:47 2017 Dylan Deu
*/

#include	<stdio.h>
#include	"utils/send.h"
#include	"graphic_actions/actions.h"

bool	msz(t_game *game, char *line)
{
  (void)line;
  my_send(game->graph_client, "msz %u %u\n", game->map->width,
	  game->map->height);
  return (true);
}
