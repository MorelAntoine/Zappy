/*
** get_nb_cmd.c for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:06:44 2017 Dylan Deu
** Last update Mon Jun 26 15:06:45 2017 Dylan Deu
*/

#include		"buffer/circular_buffer.h"

size_t			get_nb_cmd(t_buff *buff)
{
  size_t 		nb;
  int			index;

  nb = 0;
  index = buff->ird;
  while (index % BUFF_SIZE != buff->iwr)
  {
    if (buff->buf[index] == '\n')
      nb += 1;
    index = (index + 1) % BUFF_SIZE;
  }
  return (nb);
}
