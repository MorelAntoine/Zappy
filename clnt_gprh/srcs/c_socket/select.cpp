#include	<c_socket/select.hpp>

Select::Select(const int s, const int u) : maxFd(0), selectExec(false), u(u), s(s)
{
}

Select::~Select()
{
}

void Select::fdSet(int fd)
{
  if (this->selectExec)
  {
    this->selectExec = false;
    FD_ZERO(&this->rd);
    maxFd = 0;
  }
  if (fd > maxFd)
    maxFd = fd;
  FD_SET(fd, &rd);
}

bool Select::fdIsSet(int fd)
{
  if (FD_ISSET(fd, &this->rd))
    return true;
  return false;
}

bool Select::select(void)
{
  this->selectExec = true;
  this->tv.tv_usec = this->u;
  this->tv.tv_sec = this->s;
  if (::select(this->maxFd + 1, &this->rd, NULL, NULL, &this->tv) == -1)
    return false;
  else
    return true;
}

