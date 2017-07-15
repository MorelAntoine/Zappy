/*
** circular_buffer.h for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/buffer
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 14:58:46 2017 Dylan Deu
** Last update Mon Jun 26 14:58:47 2017 Dylan Deu
*/

#ifndef			CIRCULAR_BUFFER_
# define		CIRCULAR_BUFFER_

#include		<stddef.h>
#include		<unistd.h>
#include		"utils/bool.h"

#ifndef			BUFF_SIZE
# define		BUFF_SIZE 2048
#endif			/* !BUFF_SIZE */

typedef struct		s_buff
{
  char			buf[2048];
  int			ird;
  int			iwr;
}			t_buff;

t_buff			*init_buff();

void			clean_buff(t_buff *);
void			buff_write(t_buff *, char *, ssize_t);

char			*buff_read(t_buff *);

size_t			get_free_size(t_buff *);
size_t			get_read_size(t_buff *);
size_t			get_nb_cmd(t_buff *);

bool			is_crlf(t_buff *);
bool			is_lf(t_buff *);

#endif			/* !CIRCULAR_BUFFER_ */
