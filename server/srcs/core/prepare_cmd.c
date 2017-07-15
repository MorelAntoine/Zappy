/*
** prepare_cmd.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Fri Jun 16 13:20:46 2017 Dylan Deu
** Last update Fri Jun 16 13:20:46 2017 Dylan Deu
*/

#include		<time.h>
#include		<string.h>
#include		<stdio.h>
#include		"utils/time.h"
#include		"player_actions/queue_member.h"
#include		"player_actions/actions_list.h"

static unsigned long long int	get_exec_time(t_game *game, t_client *client,
						   int index)
{
  t_queue_member		*action;
  unsigned long long int	exec;

  exec = 0;
  action = list_get_first(game->queue);
  while (action)
  {
    if (action->client == client && action->time > exec)
      exec = action->time + (g_actions_time[index] * 1E6 / game->f);
    action = list_get_next(game->queue);
  }
  if (exec == 0)
    exec = get_time() + (g_actions_time[index] * 1E6 / game->f);
  return (exec);
}

bool				prepare_cmd(t_game *game, t_client *client,
						int index)
{
  t_queue_member		*action;
  char				*cmd;

  (void)g_actions;
  action = malloc(sizeof(t_queue_member));
  if (action == NULL)
  {
    perror("malloc() : prepare_map()");
    return (false);
  }
  action->action = index;
  action->client = client;
  cmd = strtok(NULL, "\0");
  if (cmd != NULL)
    action->cmd = strdup(cmd);
  else
    action->cmd = strdup("");
  action->time = get_exec_time(game, client, index);
  list_push_back(game->queue, action);
  if (strcmp(g_actions_name[index], "Incantation") == 0)
    start_incantation(game, client);
  if (strcmp(g_actions_name[index], "Fork") ==  0)
    start_fork(game, client);
  return (true);
}
