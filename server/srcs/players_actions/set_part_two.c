/*
** set_part_two.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:55:06 2017 Dylan Deu
** Last update Mon Jun 26 14:55:06 2017 Dylan Deu
*/

#include	<stdio.h>
#include	"utils/send.h"
#include	"player_actions/actions.h"

bool		set_mendiane(t_game *game, t_client *client)
{
  if (!client->stones->mendiane)
    return (false);
  game->map->content[client->pos_y * game->map->width
		     + client->pos_x]->stones->mendiane += 1;
  client->stones->mendiane -= 1;
  if (game->graph_client != -1)
    my_send(game->graph_client, "pdr %u 4\n", client->id);
  return (true);
}

bool		set_thystame(t_game *game, t_client *client)
{
  if (!client->stones->thystame)
    return (false);
  game->map->content[client->pos_y * game->map->width
		     + client->pos_x]->stones->thystame += 1;
  client->stones->thystame -= 1;
  if (game->graph_client != -1)
    my_send(game->graph_client, "pdr %u 6\n", client->id);
  return (true);
}

bool		set_phiras(t_game *game, t_client *client)
{
  if (!client->stones->phiras)
    return (false);
  game->map->content[client->pos_y * game->map->width
		     + client->pos_x]->stones->phiras += 1;
  client->stones->phiras -= 1;
  if (game->graph_client != -1)
    my_send(game->graph_client, "pdr %u 5\n", client->id);
  return (true);
}

bool		set_sibur(t_game *game, t_client *client)
{
  if (!client->stones->sibur)
    return (false);
  game->map->content[client->pos_y * game->map->width
		     + client->pos_x]->stones->sibur += 1;
  client->stones->sibur -= 1;
  if (game->graph_client != -1)
    my_send(game->graph_client, "pdr %u 3\n", client->id);
  return (true);
}

