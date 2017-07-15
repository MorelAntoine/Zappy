//
// lexing.cpp for zappy in /mnt/d/Projects/C/PSU_2016_zappy/ai/srcs
// 
// Made by DESKTOP-DHNB9O5
// Login   <antoine.morel@epitech.eu>
// 
// Started on  Wed Jun 14 20:18:41 2017 DESKTOP-DHNB9O5
// Last update Wed Jun 14 21:43:32 2017 DESKTOP-DHNB9O5
//

#include			<cstdint>
#include			<cstring>
#include			<cctype>
#include			"args/args.hpp"

static bool			isNumber(const char *nbr)
{
  uint16_t			index;

  for (index = 0; nbr[index] != '\0'; index++)
    {
      if (!isdigit(nbr[index]))
	return (false);
    }
  return (true);
}

static Zappy::Ai::Args::Flag	getFlagType(const char *flag)
{
  if (strcmp(flag, "-p") == 0)
    return (Zappy::Ai::Args::Flag::PORT);
  else if (strcmp(flag, "-n") == 0)
    return (Zappy::Ai::Args::Flag::TEAMNAME);
  else if (strcmp(flag, "-h") == 0)
    return (Zappy::Ai::Args::Flag::MACHINE);
  return (Zappy::Ai::Args::Flag::UNKNOWN);
}

static bool			argsSyntax(const int argc, char **argv)
{
  uint8_t			index;
  bool				flag(true);
  Zappy::Ai::Args::Flag		type(Zappy::Ai::Args::Flag::UNKNOWN);

  if (argc < 5)
    return (false);
  for (index = 1; index < argc; index++)
    {
      if (flag)
	{
	  type = getFlagType(argv[index]);
	  if (type == Zappy::Ai::Args::Flag::UNKNOWN)
	    return (false);
	}
      else
	{
	  if (type == Zappy::Ai::Args::Flag::PORT)
	    if (!isNumber(argv[index]))
	      return (false);
	}
      flag = (flag ? false : true);
    }
  if (!flag)
    return (false);
  return (true);
}

static bool			isHelpFlag(const int argc, char **argv)
{
  if (argc != 2)
    return (false);
  if (strcmp(argv[1], "--help") != 0)
    return (false);
  return (true);
}

bool				Zappy::Ai::Args::lexer(const int argc, char **argv)
{
  if (isHelpFlag(argc, argv))
    return (true);
  if (!argsSyntax(argc, argv))
    return (false);
  return (true);
}
