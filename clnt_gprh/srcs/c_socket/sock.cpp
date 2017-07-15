#include	<regex.h>
#include	<error.hpp>
#include	<arpa/inet.h>
#include	<unistd.h>
#include	<netdb.h>
#include	<cstring>
#include	<sys/ioctl.h>
#include	<fcntl.h>
#include <sstream>
#include	"c_socket/sock.hpp"

Sock::Sock(const std::string &ipHost, const std::string &Port)
{
  uint32_t ip = 0;
  int port = 0;

  if (this->checkIP(ipHost.c_str()))
  {
    ip = this->convIPtoNumber(ipHost.c_str());
    port = std::atoi(Port.c_str());
  }
  this->createTCPSocketIP();
  this->connectToServer(ip ,port);
  this->sendLine("toto\n");
}

Sock::~Sock()
{
  fclose(this->f_fd);
  shutdown(this->fd, 2);
  std::cout << "Delet me" << std::endl;
}

bool Sock::createTCPSocketIP()
{
  struct protoent	*pe;
  int			fd;
  int			opt;

  pe = getprotobyname("TCP");
  if (!pe)
    throw MyError("Erreur getprotobyname");
  fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (fd == -1)
    throw MyError("Erreur open socket");
  opt = 1;
  if (setsockopt(fd, SOL_SOCKET, SO_ERROR | SO_REUSEADDR | SO_REUSEPORT, &opt,
		 sizeof(int)) == -1)
  {
    close(fd);
    throw MyError("Erreur setsockopt");
  }
  this->fd = fd;
  return (true);
}

bool Sock::connectToServer(uint32_t addr, int port)
{
  this->sock.sin_family = AF_INET;
  this->sock.sin_port = htons(port);
  this->sock.sin_addr.s_addr = addr;
  if (connect(this->fd, (struct sockaddr *)&this->sock, sizeof(this->sock)) == -1)
    throw MyError("Erreur connect");
  this->f_fd = fdopen(this->fd, "r+");
  if (!this->f_fd)
    throw  MyError("Erreur Fdopen");
  return true;
}

bool Sock::checkIP(const char *ip) const
{
  regex_t	regex;

  if (regcomp(&regex, "^([0-9]|[1-9][0-9]|1([0-9][0-9])|2([0-4][0-9]|5[0-5]))."
		"([0-9]|[1-9][0-9]|1([0-9][0-9])|2([0-4][0-9]|5[0-5]))."
		"([0-9]|[1-9][0-9]|1([0-9][0-9])|2([0-4][0-9]|5[0-5]))."
		"([0-9]|[1-9][0-9]|1([0-9][0-9])|2([0-4][0-9]|5[0-5]))$",
	      REG_NOSUB | REG_EXTENDED))
    throw MyError("Erreur RegEx");
  if (regexec(&regex, ip, 0, NULL, 0) != 0)
    throw MyError("Erreur RegEx");
  regfree(&regex);
  return (true);
}

uint32_t Sock::convIPtoNumber(const char *ip) const
{
  uint32_t	result;

  result = inet_addr(ip);
  return (result);
}

void		Sock::readBuf(void)
{
  char tmp[256];
  size_t len;
  int nbToRead;
  int ret;

  nbToRead = 0;
  len = 1;
  this->os.clear();
  ioctl(this->fd, FIONREAD, &nbToRead);
  if (nbToRead <= 0)
  {
    throw MyError("server disconected");
  }
  while (len != 0)
  {
    ioctl(this->fd, FIONREAD, &nbToRead);
    if (nbToRead <= 0)
      return;
    ret = read(fd, tmp, 255);
    if (ret == -1)
      throw MyError("Server Disconected");
    tmp[ret] = 0;
    this->os << tmp;
  }
}

bool Sock::sendLine(const std::string &msg) const
{
  if (send(this->fd, msg.c_str(), msg.size(), MSG_CONFIRM))
    return (true);
  return (false);
}

int Sock::getFd(void) const
{
  return this->fd;
}

bool Sock::isFdOk(void) const
{
  int nbBuf = 0;
  ioctl(fd, FIONREAD, &nbBuf);
  if (nbBuf == 0)
    return false;
  return true;
}

char *Sock::readLine(void)
{
  this->os.getline(this->buf, 255);
  if (os.gcount() == 0)
    return NULL;
  return this->buf;
}
