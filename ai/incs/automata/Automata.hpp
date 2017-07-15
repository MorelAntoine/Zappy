//
// Automata.hpp for zappy in /mnt/d/Projects/C/PSU_2016_zappy/ai/incs/automata
// 
// Made by DESKTOP-DHNB9O5
// Login   <antoine.morel@epitech.eu>
// 
// Started on  Thu Jun 22 11:37:54 2017 DESKTOP-DHNB9O5
// Last update Sun Jul  2 21:34:11 2017 DESKTOP-DHNB9O5
//

#ifndef					AUTOMATA_HPP_
#define					AUTOMATA_HPP_

#include				<cstdint>
#include				<string>
#include				"trantorian/Trantorian.hpp"

namespace Zappy
{
  namespace Ai
  {
    class Automata
    {
    public:
      enum State
	{
	  E0, E1, E2, E3, E4, E5, E6, E7,
	  E100, E101, E102, E103, E104, E105, E106, E107, E108, E120, E121,
	  E200, E201
	};

    public:
      const static uint16_t		MAX_FOOD = 40;
      const static uint16_t		CRIT_FOOD = 15;

    private:
      Zappy::Ai::Trantorian		&trantorian;
      State				state;
      std::string			objToCollect;
      std::string			objToSet;
      int16_t				dir;
      int32_t				idToFollow;
      std::string			endCastStatus;
      uint16_t				stackAction;
      uint16_t				caseToGo;
      
      /*
      ** MANAGER
      */
    public:
      Automata(Zappy::Ai::Trantorian &_trantorian);
      ~Automata(void);
      void				run(void);
    private:
      uint16_t				getCaseToGoFromLook(void);

      /*
      ** REQUEST
      */
    private:
      void				request(void);
      void				collectRequest(void);
      void				castRequest(void);
      void				servantRequest(void);
      void				goToDir(void);
      void				goToCase(void);

      /*
      ** MESSAGE
      */
      private:
      void				treatMessage(void);
      bool				hasSameLevel(void);
      int32_t				getIdToFollow(void);
      int16_t				getDir(void);

      /*
      ** TRANSITOR
      */
    private:
      void				transitor(void);
      void				collectTransitor(void);
      void				castTransitor(void);
    };
  }
}

#endif					/* !AUTOMATA_HPP_ */
