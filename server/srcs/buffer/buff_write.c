/*
** buff_write.c for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:06:30 2017 Dylan Deu
** Last update Mon Jun 26 15:06:31 2017 Dylan Deu
*/

#include		"buffer/circular_buffer.h"

void			buff_write(t_buff *buff, char *str, ssize_t size)
{
  unsigned int		index;

  index = 0;
  while (index < size && str[index])
  {
    buff->buf[buff->iwr] = str[index];
    buff->iwr = (buff->iwr + 1) % BUFF_SIZE;
    index++;
  }
}
