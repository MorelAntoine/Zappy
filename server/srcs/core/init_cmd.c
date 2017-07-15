/*
** init_cmd.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 16:03:08 2017 Dylan Deu
** Last update Mon Jun 26 16:03:08 2017 Dylan Deu
*/

#include		<stdio.h>
#include		<string.h>
#include		"core/core.h"
#include		"utils/send.h"
#include		"game/client.h"
#include		"player_actions/actions_list.h"

void			init_cmd(t_game *game, t_client *client, char *token)
{
  int			index;

  index = 0;
  (void)g_actions;
  (void)g_actions_time;
  while (g_actions_name[index])
  {
    if (strcmp(g_actions_name[index], token) == 0)
    {
      prepare_cmd(game, client, index);
      break;
    }
    index++;
  }
  if (g_actions_name[index] == NULL && client->disconnect == false)
    my_send(client->fd, "ko\n");
}
