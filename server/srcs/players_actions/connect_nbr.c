/*
** connect_nbr.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:54:31 2017 Dylan Deu
** Last update Mon Jun 26 14:54:31 2017 Dylan Deu
*/

#include	<stdio.h>
#include	<string.h>
#include	"utils/send.h"
#include	"player_actions/actions.h"
#include	"utils/list.h"

bool	connect_nbr(t_game *game, t_client *client, char *line)
{
  (void)line;
  if (client->disconnect == false)
    my_send(client->fd, "%u\n", game->max_players_team
				- client->team->nb_players);
  return (true);
}
