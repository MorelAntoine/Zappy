#include	<iostream>
#include	<cstring>
#include	<error.hpp>
#include	<graph/display.hpp>
#include	<c_socket/select.hpp>
#include <sstream>
#include	"c_socket/sock.hpp"

static void	usage(const std::string &bin)
{
  std::cout << "USAGE :" << std::endl ;
  std::cout << bin << " -p PORT -h host" << std::endl;
}

static void loop(Sock *sock, Select *select, Graph::Display *disp)
{
  char 			*tmp;

  tmp = NULL;
  sock->sendLine("GRAPHIC\n");
  while (42)
  {
    select->fdSet(sock->getFd());
    if (select->select() == true)
    {
     // std::cout << "select ok" << std::endl;
      if (select->fdIsSet(sock->getFd()) == true)
      {
	sock->readBuf();
	while ((tmp = sock->readLine()))
	  disp->processLine(std::string(tmp));
      }
    }
    else
    {
      std::cout << "select fail" << std::endl;
      break;
    }
    if (disp->display() == false)
    {
      break;
    }
  }
}

int		main(int ac, char **av)
{
  Sock		*srvCom = NULL;
  Graph::Display *disp = NULL;
  Select	*select = NULL;

  try
  {
    if (ac == 1)
	srvCom = new Sock("127.0.0.1", "4242");
    else if (ac == 5)
    {
      if (std::strcmp("-p", av[1]) == 0 && std::strcmp("-h", av[3]) == 0)
	  srvCom = new Sock(av[4], av[2]);
      else
      {
	usage(av[0]);
	return (1);
      }
    }
    else
    {
      usage(av[0]);
      return (1);
    }
    select = new Select(0, 100);
    disp = new Graph::Display(av, ac);
    loop(srvCom, select, disp);

  }
  catch (MyError ex)
  {
    std::cerr << "Error init socket : " << ex.what() << std::endl;
    return (1);
  }
  if (srvCom)
    delete srvCom;
  if (disp)
    delete disp;
  return (0);
}
