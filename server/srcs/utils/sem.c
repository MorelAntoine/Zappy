/*
** sem.c.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Tue Jun 13 15:05:05 2017 Dylan Deu
** Last update Tue Jun 13 15:05:05 2017 Dylan Deu
*/

#include	<sys/sem.h>
#include	<sys/shm.h>
#include	"utils/shared_memory.h"

void		sem_lock(int sem_id)
{
  struct sembuf sops;

  sops.sem_num = 0;
  sops.sem_flg = 0;
  sops.sem_op = -1;
  semop(sem_id, &sops, 1);
}

void		sem_unlock(int sem_id)
{
  struct sembuf sops;

  sops.sem_num = 0;
  sops.sem_flg = 0;
  sops.sem_op = 1;
  semop(sem_id, &sops, 1);
}

void		get_sem(t_shared_server_memory *new)
{
  new->sem_id = semget(new->key, 1, SHM_R | SHM_W);
  if (new->sem_id == -1)
  {
    new->sem_id = semget(new->key, 1, IPC_CREAT | SHM_R | SHM_W);
    semctl(new->sem_id, 0, SETVAL, 1);
  }
}
