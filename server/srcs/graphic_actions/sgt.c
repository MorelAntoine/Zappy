/*
** sgt.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:53:58 2017 Dylan Deu
** Last update Mon Jun 26 14:53:58 2017 Dylan Deu
*/

#include	<stdio.h>
#include	"utils/send.h"
#include	"graphic_actions/actions.h"
#include	"game/client.h"

bool	sgt(t_game *game, char *line)
{
  (void)line;
  my_send(game->graph_client, "sgt %u\n", game->f);
  return (true);
}
