/*
** clean_game.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed Jun 28 15:23:51 2017 Dylan Deu
** Last update Wed Jun 28 15:23:51 2017 Dylan Deu
*/

#include		"player_actions/queue_member.h"
#include		"game/client.h"

void			clean_game(t_game *game)
{
  t_queue_member	*action;
  t_client		*client;

  client = list_get_first(game->clients);
  while (client)
  {
    client_delete(client, true);
    list_delete_node(game->clients, client, false);
    client = list_get_next(game->clients);
  }
  action = list_get_first(game->queue);
  while (action)
  {
    free(action->cmd);
    list_delete_node(game->queue, action, false);
    free(action);
    action = list_get_next(game->queue);
  }
}
