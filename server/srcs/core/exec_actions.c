/*
** exec_actions.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Fri Jun 16 15:20:01 2017 Dylan Deu
** Last update Fri Jun 16 15:20:01 2017 Dylan Deu
*/

#include		<time.h>
#include		"utils/time.h"
#include		"player_actions/queue_member.h"
#include		"player_actions/actions_list.h"

static void		exec_action(t_game *game, t_queue_member *action)
{
  if (action->client != NULL && action->cmd != NULL &&
    action->client->buffer != NULL)
  {
    (g_actions[action->action])(game, action->client, action->cmd);
  }
}

void			check_actions(t_game *game)
{
  t_queue_member		*action;
  unsigned long long int	actual_time;

  (void)g_actions_time;
  (void)g_actions_name;
  action = list_get_first(game->queue);
  actual_time = get_time();
  while (action)
  {
    if (actual_time > action->time)
    {
      exec_action(game, action);
      if (action != NULL)
	free(action->cmd);
      list_delete_node(game->queue, action, false);
      free(action);
    }
    action = list_get_next(game->queue);
  }
}
