#ifndef CLNT_GPRH_SELECT_HPP
#define CLNT_GPRH_SELECT_HPP

#include <sys/time.h>
#include <stdlib.h>

class Select
{
public:
  Select(const int, const int);
  ~Select();

  void	fdSet(int);
  bool	fdIsSet(int);
  bool	select(void);
private:
  struct timeval	tv;
  fd_set		rd;
  int			maxFd;
  bool			selectExec;
  int			u;
  int			s;
};

#endif /* !CLNT_GPRH_SELECT_HPP_ */
