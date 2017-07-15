//
// Trantorian.hpp for zappy in /mnt/d/Projects/C/PSU_2016_zappy/ai
// 
// Made by DESKTOP-DHNB9O5
// Login   <antoine.morel@epitech.eu>
// 
// Started on  Thu Jun 22 11:46:43 2017 DESKTOP-DHNB9O5
// Last update Wed Jun 28 19:09:49 2017 DESKTOP-DHNB9O5
//

#ifndef					TRANTORIAN_HPP_
#define					TRANTORIAN_HPP_

#include				<cstdint>
#include				<string>
#include				"client/Client.hpp"

namespace Zappy
{
  namespace Ai
  {
    class Trantorian
    {
    public:
      const uint16_t	ELEVATION_SECRET[7][7] =
	{
	  { 1, 1, 0, 0, 0, 0, 0 },
	  { 2, 1, 1, 1, 0, 0, 0 },
	  { 2, 2, 0, 1, 0, 2, 0 },
	  { 4, 1, 1, 2, 0, 1, 0 },
	  { 4, 1, 2, 1, 3, 0, 0 },
	  { 6, 1, 2, 3, 0, 1, 0 },
	  { 6, 2, 2, 2, 2, 2, 1 }
	};
	enum ElevIdx
	  {
	    NB_PERS = 0,
	    LINEMATE,
	    DERAUMERE,
	    SIBUR,
	    MENDIANE,
	    PHIRAS,
	    THYSTAME
	  };
	
    private:
      bool				alive;
      const std::string			team;
      uint16_t				level;
      Zappy::Ai::Client			*client;
      const int32_t			id;

      /*
      ** MANAGER
      */
    public:
      Trantorian(const std::string &_team, Zappy::Ai::Client *_client);
      ~Trantorian(void);
      bool				isAlive(void) const;
      void				setAlive(const bool status);
      std::string			getTeam(void) const;
      uint16_t				getLevel(void) const;
      void				levelUp(void);
      Zappy::Ai::Client			*getClient(void);
      int32_t				getId(void) const;

      /*
      ** COMMANDS
      */
    public:
      bool				forward(void) const;
      bool				right(void) const;
      bool				left(void) const;
      bool				look(void) const;
      bool				inventory(void) const;
      bool				broadcast(const std::string &text) const;
      bool				connectNbr(void) const;
      bool				fork(void) const;
      bool				eject(void) const;
      bool				take(const std::string &object) const;
      bool				set(const std::string &object) const;
      bool				incantation(void) const;

      /*
      ** TOOLS
      */
    public:
      uint16_t				getFromInventoryTheValueOf(const std::string &object);
      bool				onCase(const std::string &object);
      std::string			getArgFromMessage(const std::string &flag);
      bool				caseIsEmpty(void);
      std::string			popElemOnCase(void);
      bool				isAloneOnCase(void);
      uint32_t				onCaseCount(const std::string &obj);
      std::string			getRequireStone(void);
      bool				enoughPersOnCase(void);
      std::string			stoneToSet(void);
    };
  }
}

#endif					/* !TRANTORIAN_HPP_ */
