/*
** graph_init.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 16:06:09 2017 Dylan Deu
** Last update Mon Jun 26 16:06:09 2017 Dylan Deu
*/

#include		"game/client.h"
#include		"graphic_actions/actions_list.h"

bool			graph_init(t_game *game, t_client *client, char *cmd)
{
  (void)g_graphic_actions_name;
  game->graph_client = client->fd;
  client_delete(client, false);
  list_delete_node(game->clients, client, false);
  (g_graphic_actions[0])(game, cmd);
  return (false);
}
