/*
** time.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:55:50 2017 Dylan Deu
** Last update Mon Jun 26 14:55:50 2017 Dylan Deu
*/

#include	<time.h>

unsigned long long int	get_time(void)
{
  struct timespec       ts;
  unsigned long long int	result;

  clock_gettime(CLOCK_MONOTONIC, &ts);
  result = (unsigned long long int)ts.tv_sec;
  result *= 1E6;
  result += (unsigned long long int)ts.tv_nsec / 1E3;
  return (result);
}
