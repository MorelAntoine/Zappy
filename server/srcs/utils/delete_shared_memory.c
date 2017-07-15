/*
** delete_shared_memory.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Tue Jun 13 15:40:01 2017 Dylan Deu
** Last update Tue Jun 13 15:40:01 2017 Dylan Deu
*/

#include		<sys/sem.h>
#include		<sys/shm.h>
#include		"utils/shared_memory.h"

void			delete_shared_memory(t_shared_server_memory *shm)
{
  semctl(shm->sem_id, IPC_RMID, 0);
  shmctl(shm->shm_id, IPC_RMID, 0);
}
