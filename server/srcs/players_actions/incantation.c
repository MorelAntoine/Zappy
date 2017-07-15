/*
** incantation.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:54:47 2017 Dylan Deu
** Last update Mon Jun 26 14:54:47 2017 Dylan Deu
*/

#include	<stdio.h>
#include	"player_actions/incantation.h"
#include	"utils/send.h"

static bool	check_incantation_stones(t_game *game, t_client *client,
					 bool update)
{
  t_stone_list	*box;
  t_stone_list	*stones;

  box = game->map->content[client->pos_y * game->map->width
			   + client->pos_x]->stones;
  stones = &(g_list_stones[client->level - 1]);
  if (box->linemate != stones->linemate
      || box->deraumere != stones->deraumere
      || box->sibur != stones->sibur
      || box->mendiane != stones->mendiane
      || box->phiras != stones->phiras
      || box->thystame != stones->thystame
      || game->map->content[client->pos_y * game->map->width
			    + client->pos_x]->food != 0)
    return (false);
  if (update)
    {
      box->linemate -= stones->linemate;
      box->deraumere -= stones->deraumere;
      box->sibur -= stones->sibur;
      box->mendiane -= stones->mendiane;
      box->phiras -= stones->phiras;
      box->thystame -= stones->thystame;
    }
  return (true);
}

bool	incantation_is_possible(t_game *game, t_client *client, bool ud)
{
  unsigned int	players;
  t_client	*clientit;

  players = 1;
  clientit = list_get_first(game->clients);
  while (clientit)
    {
      if (clientit != client && clientit->level == client->level
	 && clientit->pos_x == client->pos_x
	 && clientit->pos_y == client->pos_y)
	players++;
      clientit = list_get_next(game->clients);
    }
  if (players != g_list_users[client->level - 1])
    return (false);
  return (check_incantation_stones(game, client, ud));
}

bool	start_incantation(t_game *game, t_client *client)
{
  if (incantation_is_possible(game, client, false))
    {
      if (client->disconnect == false)
	my_send(client->fd, "Elevation underway\n");
      if (game->graph_client != -1)
	my_send(game->graph_client, "pic %u %u %u %u\n",
		client->pos_x, client->pos_y,
		client->level, client->id);
      return (true);
    }
  if (client->disconnect == false)
    my_send(client->fd, "ko\n");
  return (false);
}

static bool	all_players_up(t_game *game, t_client *client, int lvl)
{
  t_client	*it;
  t_box		*box;

  it = list_get_first(game->clients);
  while (it)
    {
      if (it->level == (unsigned int)lvl && it->pos_x == client->pos_x &&
	it->pos_y == client->pos_y && it->disconnect == false)
	{
	  it->level += 1;
	  my_send(client->fd, "Current level: %u\n", it->level);
	  if (game->graph_client > 0)
	    my_send(game->graph_client, "plv %u %u\n", it->id, it->level);
	  update_player_team(game, client);
	}
      it = list_get_next(game->clients);
    }
  box = game->map->content[client->pos_y * game->map->width + client->pos_x];
  if (game->graph_client > 0)
    my_send(game->graph_client, "bct %u %u %u %u %u %u %u %u %u\n",
	    client->pos_x, client->pos_y,
	    box->food, box->stones->linemate, box->stones->deraumere,
	    box->stones->sibur, box->stones->mendiane,
	    box->stones->phiras, box->stones->thystame);
  return (true);
}

bool	incantation(t_game *game, t_client *client, char *line)
{
  int	lvl;

  (void)line;
  if (incantation_is_possible(game, client, true))
    {
      if (game->graph_client > 0)
	my_send(game->graph_client, "pie %u %u %d\n",
		client->pos_x, client->pos_y, 1);
      lvl = client->level;
      all_players_up(game, client, lvl);
      return (true);
    }
  if (client->disconnect == false)
    my_send(client->fd, "ko\n");
  if (game->graph_client > 0)
    my_send(game->graph_client, "pie %u %u %d\n",
	    client->pos_x, client->pos_y, 0);
  return (true);
}
