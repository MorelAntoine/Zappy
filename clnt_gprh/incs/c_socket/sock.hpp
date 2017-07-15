#ifndef		CLNT_GPRH_SOCK_HPP
# define	CLNT_GPRH_SOCK_HPP

# include	<iostream>
# include	<cstdio>
# include	<netinet/in.h>


class		Sock
{
public:
  Sock(const std::string &, const std::string &);
  virtual ~Sock();

public:
  char			*readLine(void);
  void		readBuf(void);
  bool	sendLine(const std::string &) const;
  int		getFd(void)const;
  bool		isFdOk(void) const;

private:
  bool		createTCPSocketIP();
  bool		connectToServer(uint32_t addr, int port);
  bool		checkIP(const char *ip) const;
  uint32_t	convIPtoNumber(const char *ip) const;
private:
  int			fd;
  FILE			*f_fd;
  struct sockaddr_in	sock;
  std::stringstream	os;
  char			buf[256];

};

#endif			/* !CLNT_GPRH_SOCK_HPP_ */
