//
// get.cpp for zappy in /mnt/d/Projects/C/PSU_2016_zappy/ai
// 
// Made by DESKTOP-DHNB9O5
// Login   <antoine.morel@epitech.eu>
// 
// Started on  Fri Jun 16 18:14:55 2017 DESKTOP-DHNB9O5
// Last update Fri Jun 16 21:11:13 2017 DESKTOP-DHNB9O5
//

#include			<cstring>
#include			<string>
#include			"args/args.hpp"

std::string			Zappy::Ai::Args::get(const int argc, char **argv,
						     const char *flag)
{
  uint8_t			index;
  bool				hasFlag(false);

  for (index = 1; index < argc; index++)
    {
      if (hasFlag)
	return (argv[index]);
      else if (strcmp(argv[index], flag) == 0)
	hasFlag = true;
    }
  return ("");
}
