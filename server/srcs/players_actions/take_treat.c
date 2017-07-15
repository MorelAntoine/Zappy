/*
** take_treat.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Sun Jul 02 20:07:21 2017 Dylan Deu
** Last update Sun Jul 02 20:07:21 2017 Dylan Deu
*/

#include	<string.h>
#include	"utils/send.h"
#include	"player_actions/take.h"
#include	"game/client.h"

bool		take_treat(t_game *game, t_client *client,
			       char *object, int index)
{
  if (strcmp(object, g_list_objects[index]) == 0)
  {
    if (g_list_actions[index](game, client))
      take_send(game, client);
    else
    {
      if (client->disconnect == false)
	my_send(client->fd, "ko\n");
    }
    return (true);
  }
  return (false);
}
