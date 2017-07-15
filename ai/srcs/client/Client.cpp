//
// Client.cpp for zappy in /mnt/d/Projects/C/PSU_2016_zappy/ai/srcs
// 
// Made by DESKTOP-DHNB9O5
// Login   <antoine.morel@epitech.eu>
// 
// Started on  Wed Jun 14 14:56:49 2017 DESKTOP-DHNB9O5
// Last update Sun Jul  2 21:52:01 2017 DESKTOP-DHNB9O5
//

#include			<cstring>
#include			<iostream>
#include			<arpa/inet.h>
#include			<netdb.h>
#include			<sys/types.h>
#include			<sys/socket.h>
#include			<unistd.h>
#include			<fcntl.h>
#include			"client/Client.hpp"

Zappy::Ai::Client::Client(void)
  : sock(Zappy::Ai::Client::SOCKET_DEFAULT), port(0), addr(""), response("")
{}

Zappy::Ai::Client::~Client(void)
{
  if (this->sock != Zappy::Ai::Client::SOCKET_DEFAULT)
    ::close(this->sock);
}

int32_t				Zappy::Ai::Client::getSock(void) const
{ return (this->sock); }

uint16_t			Zappy::Ai::Client::getPort(void) const
{ return (this->port); }

void				Zappy::Ai::Client::setPort(const uint16_t src)
{ this->port = src; }

std::string			Zappy::Ai::Client::getAddr(void) const
{ return (this->addr); }

void				Zappy::Ai::Client::setAddr(const std::string &src)
{ this->addr = src; }

void				Zappy::Ai::Client::clearResponseBuffer(void)
{ this->response = ""; }

bool				Zappy::Ai::Client::connect(const uint16_t port, const std::string &addr,
							   const std::string &team)
{
  std::string			response;

  if (!this->createSocket("TCP"))
    return (false);
  if (!this->connectSocket(port, addr))
    return (false);
  this->getResponse();
  this->send(team);
  response = this->getResponse();
  if (response.compare(0, 2, "ko") == 0)
    return (false);
  return (true);
}

bool				Zappy::Ai::Client::close(void)
{
  if (::close(this->sock) == -1)
    return (false);
  return (true);
}

bool				Zappy::Ai::Client::send(const std::string &data) const
{
  std::string			dataFormated(data + Client::LF);

  if (fcntl(this->sock, F_GETFD) < 0)
    std::exit(EXIT_FAILURE);
  if (::send(this->sock, dataFormated.c_str(), dataFormated.size(), 0) == -1)
    std::exit(EXIT_FAILURE);
  return (true);
}

const std::string		&Zappy::Ai::Client::getResponse(void)
{
  char				buff[Zappy::Ai::Client::BUFF_SIZE];

  if (fcntl(this->sock, F_GETFD) < 0)
    std::exit(EXIT_FAILURE);
  ::bzero(buff, Zappy::Ai::Client::BUFF_SIZE);
  if (::recv(this->sock, buff, Zappy::Ai::Client::BUFF_SIZE - 1, 0) == -1)
    std::exit(EXIT_FAILURE);
  this->response = std::string(buff);
  while (this->response.back() != '\n')
    {
      if (fcntl(this->sock, F_GETFD) < 0)
	std::exit(EXIT_FAILURE);
      ::bzero(buff, Zappy::Ai::Client::BUFF_SIZE);
      if (::recv(this->sock, buff, Zappy::Ai::Client::BUFF_SIZE - 1, 0) == -1)
	std::exit(EXIT_FAILURE);
      this->response = std::string(this->response + buff);
    }
  return (this->response);
}

std::string			Zappy::Ai::Client::getCurrentResponse(void)
{
  std::string			responseCopy(this->response);
  char				*token;

  token = std::strtok(const_cast<char *>(responseCopy.c_str()), Client::LF);
  if (token == NULL)
    {
      token = std::strtok(const_cast<char *>(responseCopy.c_str()), " ");
      if (!token)
	return ("");
    }
  return (token);
}

void				Zappy::Ai::Client::nextResponse(void)
{
  std::size_t			pos;

  pos = this->response.find(Client::LF);
  if (pos != std::string::npos && pos + 1 < this->response.size())
    this->response = this->response.substr(pos + 1);
  else
    this->response = "";
}

bool				Zappy::Ai::Client::createSocket(const std::string &protoname)
{
  struct protoent		*pe;

  if (this->sock != Zappy::Ai::Client::SOCKET_DEFAULT)
    {
      if (::close(this->sock) == Zappy::Ai::Client::SOCKET_ERROR)
	return (false);
      this->sock = Zappy::Ai::Client::SOCKET_DEFAULT;
    }
  pe = getprotobyname(protoname.c_str());
  if (!pe)
    return (false);
  this->sock = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (this->sock == Zappy::Ai::Client::SOCKET_ERROR)
    return (false);
  return (true);
}

bool				Zappy::Ai::Client::connectSocket(const uint16_t port,
								 const std::string &addr)
{
  struct sockaddr_in		sin;
  int32_t			status;

  sin.sin_addr.s_addr = inet_addr(addr.c_str());
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  status = ::connect(this->sock, (const struct sockaddr *)(&sin), sizeof(sin));
  if (status == Zappy::Ai::Client::SOCKET_ERROR)
    return (false);
  return (true);
}
