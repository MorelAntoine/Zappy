//
// main.cpp for zappy in /mnt/d/Projects/C/PSU_2016_zappy/ai/srcs
// 
// Made by DESKTOP-DHNB9O5
// Login   <antoine.morel@epitech.eu>
// 
// Started on  Tue Jun 13 13:44:17 2017 DESKTOP-DHNB9O5
// Last update Wed Jun 28 15:08:34 2017 DESKTOP-DHNB9O5
//

#include				<iostream>
#include				<cstdlib>
#include				<cstring>
#include				<ctime>
#include				<string>
#include				"args/args.hpp"
#include				"automata/Automata.hpp"

static bool				zappyAi(const uint16_t port,
						const std::string &team,
						const std::string &addr)
{
  Zappy::Ai::Client			client;

  client.setPort(port);
  client.setAddr(addr);
  if (!client.connect(port, addr, team))
    return (false);
  
  std::srand(std::time(NULL));
  Zappy::Ai::Trantorian			trantorian(team, &client);
  Zappy::Ai::Automata			automata(trantorian);
  automata.run();
  return (true);
}

static void				displayUsage(std::string binaryName)
{
  std::cout
    << "USAGE: " << binaryName << " -p port -n name -h machine" << std::endl
    << "\tport\tis the port number" << std::endl
    << "\tname\tis the name of the team" << std::endl
    << "\tmachine\tis the name of the machine; localhost by default"
    << std::endl;
}

int					main(int argc, char **argv)
{
  std::string				port;
  std::string				team;
  std::string				addr;

  if (!Zappy::Ai::Args::lexer(argc, argv))
    {
      displayUsage(argv[0]);
      return (EXIT_FAILURE);
    }
  if (strcmp(argv[1], "--help") == 0)
    {
      displayUsage(argv[0]);
      return (EXIT_SUCCESS);
    }
  port = Zappy::Ai::Args::get(argc, argv, "-p");
  team = Zappy::Ai::Args::get(argc, argv, "-n");
  if (port.size() == 0 || team.size() == 0)
    {
      displayUsage(argv[0]);
      return (EXIT_FAILURE);
    }
  addr = Zappy::Ai::Args::get(argc, argv, "-h");
  if (addr.size() == 0)
    addr = "127.0.0.1";
  if (!zappyAi(std::stoi(port), team, addr))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
