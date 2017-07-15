/*
** get_free_size.c for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:07:29 2017 Dylan Deu
** Last update Mon Jun 26 15:07:30 2017 Dylan Deu
*/

#include		"buffer/circular_buffer.h"

size_t			get_free_size(t_buff *buff)
{
  size_t		size;

  if (buff->iwr >= buff->ird)
    size = (size_t)(BUFF_SIZE - (buff->iwr - buff->ird));
  else
    size = (size_t)(buff->ird - buff->iwr);
  return (size);
}

size_t			get_read_size(t_buff *buff)
{
  size_t		size;

  if (buff->ird > buff->iwr)
    size = (size_t)(BUFF_SIZE - (buff->ird - buff->iwr));
  else
    size = (size_t)(buff->iwr - buff->ird);
  return (size);
}
