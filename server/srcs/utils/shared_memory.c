/*
** shared_memory.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Tue Jun 13 14:32:34 2017 Dylan Deu
** Last update Tue Jun 13 14:32:34 2017 Dylan Deu
*/

#include			<unistd.h>
#include			<sys/types.h>
#include			<stdlib.h>
#include			<sys/ipc.h>
#include			<sys/sem.h>
#include			<stdio.h>
#include			<sys/shm.h>
#include			"utils/bool.h"
#include			"utils/shared_memory.h"

static void			get_shm(t_shared_server_memory *new)
{
  new->shm_id = shmget(new->key, 4, SHM_R | SHM_W);
  if (new->shm_id == -1)
  {
    new->key = shmget(new->key, 4, IPC_CREAT | SHM_R | SHM_W);
    new->board = (unsigned int *)(shmat(new->shm_id, NULL, SHM_R | SHM_W));
  }
  else
    new->board = (unsigned int *)(shmat(new->shm_id, NULL, SHM_R | SHM_W));
  new->board[TEAM_ONE] = 0;
  new->board[TEAM_TWO] = 0;
  new->board[MAX_LEVEL_1] = 1;
  new->board[MAX_LEVEL_2] = 1;
}

void				set_player(t_shared_server_memory *shm,
					       board index, unsigned int value)
{
  shm->board[index] = value;
}

void				set_level(t_shared_server_memory *shm,
					      board index, unsigned int value)
{
  shm->board[index] = value;
}

unsigned int			get_board_value(t_shared_server_memory *shm,
						    board index)
{
  return (shm->board[index]);
}

t_shared_server_memory		*init_shared_memory()
{
  char				buff[1024];
  char				*path;
  t_shared_server_memory	*new;

  new = malloc(sizeof(t_shared_server_memory));
  if (new == NULL)
  {
    perror("Init_shared_memory().");
    return (NULL);
  }
  path = getcwd(buff, 1024);
  if (path == NULL)
  {
    perror("Init_shared_memory().");
    return (NULL);
  }
  new->key = ftok(path, 0);
  if (new->key == -1)
  {
    perror("Init_shared_memory().");
    return (NULL);
  }
  get_shm(new);
  get_sem(new);
  return (new);
}
