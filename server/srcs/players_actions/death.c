/*
** death.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:54:35 2017 Dylan Deu
** Last update Mon Jun 26 14:54:35 2017 Dylan Deu
*/

#include		<stdio.h>
#include		<time.h>
#include		"utils/send.h"
#include		"player_actions/queue_member.h"
#include		"utils/time.h"

static bool		death(t_game *game, t_client *client, char *toto)
{
  (void)toto;
  if (game->graph_client > 0)
    my_send(game->graph_client, "pdi %u\n", client->id);
  if (client->disconnect == false)
    my_send(client->fd, "dead\n");
  if (client->team)
  {
    client->team->nb_players -= 1;
    if (client->team->max_level == client->level)
      client->team->nb_player_max_level -= 1;
  }
  return (true);
}

void			check_eggs(t_game *game)
{
  t_egg			*eggs;
  unsigned long long int	actual_time;

  eggs = list_get_first(game->eggs);
  actual_time = get_time();
  while (eggs)
  {
    if (actual_time > eggs->time_death)
      death_egg(game, eggs);
    eggs = list_get_next(game->eggs);
  }
}

static void		delete_action(t_game *game, t_client *client)
{
  t_queue_member	*action;

  action = list_get_first(game->queue);
  death(game, client, NULL);
  while (action)
  {
    if (client->fd == action->client->fd)
    {
      if (action->cmd)
	free(action->cmd);
      action->cmd = NULL;
      list_delete_node(game->queue, action, false);
      free(action);
      action = list_get_first(game->queue);
    } else
      action = list_get_next(game->queue);
  }
}

void			check_death(t_game *game)
{
  t_client			*client;
  unsigned long long int	at;
  unsigned long long int	food;

  client = list_get_first(game->clients);
  at = get_time();
  while (client)
  {
    food = (client->time_death < at) ? 0 : (client->time_death - at);
    food = (unsigned int)((float)(food) / 1000000 * game->f / 126);
    if ((at >= client->time_death && client->team != NULL && food <= 0)
	|| client->disconnect == true || client->fd < 0)
    {
      delete_action(game, client);
      client_delete(client, true);
      list_delete_node(game->clients, client, false);
    }
    client = list_get_next(game->clients);
  }
}
