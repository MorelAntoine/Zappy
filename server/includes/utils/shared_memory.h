/*
** shared_memory.h for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/utils
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:05:15 2017 Dylan Deu
** Last update Mon Jun 26 15:05:16 2017 Dylan Deu
*/

#ifndef PSU_2016_ZAPPY_SHARED_MEMORY_H
#define PSU_2016_ZAPPY_SHARED_MEMORY_H

#include		<sys/param.h>

typedef enum		e_board
{
  TEAM_ONE = 0,
  TEAM_TWO,
  MAX_LEVEL_1,
  MAX_LEVEL_2
}			board;

typedef struct		s_shared_server_memory
{
  int			shm_id;
  int			sem_id;
  key_t			key;
  unsigned int		*board;
}			t_shared_server_memory;

unsigned int			get_board_value(t_shared_server_memory *shm,
						    board value);
void				set_player(t_shared_server_memory *,
					       board, unsigned int);
void				set_level(t_shared_server_memory *,
					      board, unsigned int);
t_shared_server_memory		*init_shared_memory();
void				delete_shared_memory(t_shared_server_memory *);
void				get_sem(t_shared_server_memory *);
void				sem_unlock(int);
void				sem_lock(int);

#endif /* !PSU_2016_ZAPPY_SHARED_MEMORY_H_ */
