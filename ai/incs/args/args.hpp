//
// args.hpp for zappy in /mnt/d/Projects/C/PSU_2016_zappy/ai
// 
// Made by DESKTOP-DHNB9O5
// Login   <antoine.morel@epitech.eu>
// 
// Started on  Wed Jun 14 20:24:52 2017 DESKTOP-DHNB9O5
// Last update Fri Jun 16 21:08:20 2017 DESKTOP-DHNB9O5
//

#ifndef				ARGS_HPP_
#define				ARGS_HPP_

#include			<string>

namespace Zappy
{
  namespace Ai
  {
    namespace Args
    {
      enum Flag
	{
	  UNKNOWN,
	  PORT,
	  TEAMNAME,
	  MACHINE
	};

      bool			lexer(const int argc, char **argv);
      std::string		get(const int argc, char **argv, const char *flag);
    }
  }
}

#endif				/* !ARGS_HPP_ */
