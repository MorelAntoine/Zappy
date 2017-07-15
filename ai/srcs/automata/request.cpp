//
// request.cpp for zappy in /mnt/d/Projects/C/PSU_2016_zappy/ai/srcs/automata
// 
// Made by DESKTOP-DHNB9O5
// Login   <antoine.morel@epitech.eu>
// 
// Started on  Tue Jun 27 14:19:21 2017 DESKTOP-DHNB9O5
// Last update Sun Jul  2 23:27:25 2017 DESKTOP-DHNB9O5
//

#include				<iostream>
#include				<sstream>
#include				<chrono>
#include				<thread>
#include				"automata/Automata.hpp"

void					Zappy::Ai::Automata::request(void)
{
  if (this->state < State::E100)
    this->collectRequest();
  else if (this->state < State::E200)
    this->castRequest();
  else
    this->servantRequest();
}

void					Zappy::Ai::Automata::collectRequest(void)
{
  switch (this->state)
    {
    case State::E0: // needFood
      this->trantorian.inventory();
      break;
    case State::E1: // onCase
      this->trantorian.look();
      break;
    case State::E2: // move
      this->goToCase();
      break;
    case State::E3: // take
      this->trantorian.take(this->objToCollect);
      break;
    case State::E4: // needStone
      this->trantorian.inventory();
      break;
    case State::E5: // onCase
      this->trantorian.look();
      break;
    case State::E6: // move
      this->goToCase();
      break;
    case State::E7: // take
      this->trantorian.take(this->objToCollect);
      break;
    default:
      break;
    }
}

void					Zappy::Ai::Automata::castRequest(void)
{
  std::stringstream			ss;
  
  switch (this->state)
    {
    case State::E100: // needPers
      this->trantorian.look();
      break;
    case State::E120: // critFood
      this->trantorian.inventory();
      break;
    case State::E121: // callBreak
      std::this_thread::sleep_for(std::chrono::milliseconds(22));
      ss << " -Lv " << this->trantorian.getLevel()
	 << " -Id " << this->trantorian.getId()
	 << " -Cast break";
      this->trantorian.broadcast(ss.str());
      break;
    case State::E101: // callPers
      std::this_thread::sleep_for(std::chrono::milliseconds(22));
      ss << " -Lv " << this->trantorian.getLevel()
	 << " -Id " << this->trantorian.getId();
      this->trantorian.broadcast(ss.str());
      break;
    case State::E102: // callCast
      std::this_thread::sleep_for(std::chrono::milliseconds(22));
      ss << " -Lv " << this->trantorian.getLevel()
	 << " -Id " << this->trantorian.getId()
	 << " -Cast launch";
      this->trantorian.broadcast(ss.str());
      break;
    case State::E103: // needToClean
      this->trantorian.look();
      break;
    case State::E104: // clear
      this->trantorian.take(this->objToCollect);
      break;
    case State::E105: // stonesOnCase
      this->trantorian.look();
      break;
    case State::E106: // set
      this->trantorian.set(this->objToSet);
      break;
    case State::E107: // cast
      this->trantorian.incantation();
      break;
    case State::E108: // callEndCast
      std::this_thread::sleep_for(std::chrono::milliseconds(22));
      ss << " -Lv " << this->trantorian.getLevel()
	 << " -Id " << this->trantorian.getId()
	 << " -Cast " << this->endCastStatus;
      this->trantorian.broadcast(ss.str());
      if (this->endCastStatus.compare("success") == 0)
	this->trantorian.levelUp();
      break;
    default:
      break;
    }
}

void					Zappy::Ai::Automata::servantRequest(void)
{
  switch (this->state)
    {
    case State::E200: // goTo
      this->goToDir();
      this->dir = -1;
      break;
    case State::E201: // wait
      this->trantorian.right();
      break;
    default:
      break;
    }
}

void					Zappy::Ai::Automata::goToDir(void)
{
  switch (this->dir)
    {
    case 1:
      this->trantorian.forward();
      break;
    case 2:
      this->stackAction += 3;
      this->trantorian.forward();
      this->trantorian.left();
      this->trantorian.forward();
      break;
    case 3:
      this->stackAction += 2;
      this->trantorian.left();
      this->trantorian.forward();
      break;
    case 4:
      this->stackAction += 4;
      this->trantorian.left();
      this->trantorian.forward();
      this->trantorian.left();
      this->trantorian.forward();
      break;
    case 5:
      this->stackAction += 3;
      this->trantorian.left();
      this->trantorian.left();
      this->trantorian.forward();
      break;
    case 6:
      this->stackAction += 4;
      this->trantorian.right();
      this->trantorian.forward();
      this->trantorian.right();
      this->trantorian.forward();
      break;
    case 7:
      this->stackAction += 2;
      this->trantorian.right();
      this->trantorian.forward();
      break;
    case 8:
      this->stackAction += 3;
      this->trantorian.forward();
      this->trantorian.right();
      this->trantorian.forward();
      break;
    default:
      this->trantorian.inventory();
      break;
    }
}

void					Zappy::Ai::Automata::goToCase(void)
{
  switch (this->caseToGo)
    {
    case 1:
      this->stackAction += 3;
      this->trantorian.forward();
      this->trantorian.left();
      this->trantorian.forward();
      break;
    case 2:
      this->trantorian.forward();
      break;
    case 3:
      this->stackAction += 3;
      this->trantorian.forward();
      this->trantorian.right();
      this->trantorian.forward();
      break;
    case 4:
      this->stackAction += 5;
      this->trantorian.forward();
      this->trantorian.forward();
      this->trantorian.left();
      this->trantorian.forward();
      this->trantorian.forward();
      break;
    case 5:
      this->stackAction += 4;
      this->trantorian.forward();
      this->trantorian.forward();
      this->trantorian.left();
      this->trantorian.forward();
      break;
    case 6:
      this->stackAction += 2;
      this->trantorian.forward();
      this->trantorian.forward();
      break;
    case 7:
      this->stackAction += 4;
      this->trantorian.forward();
      this->trantorian.forward();
      this->trantorian.right();
      this->trantorian.forward();
      break;
    case 8:
      this->stackAction += 5;
      this->trantorian.forward();
      this->trantorian.forward();
      this->trantorian.right();
      this->trantorian.forward();
      this->trantorian.forward();
      break;
    case 9:
      this->stackAction += 7;
      this->trantorian.forward();
      this->trantorian.forward();
      this->trantorian.forward();
      this->trantorian.left();
      this->trantorian.forward();
      this->trantorian.forward();
      this->trantorian.forward();
      break;
    case 10:
      this->stackAction += 6;
      this->trantorian.forward();
      this->trantorian.forward();
      this->trantorian.forward();
      this->trantorian.left();
      this->trantorian.forward();
      this->trantorian.forward();
      break;
    case 11:
      this->stackAction += 5;
      this->trantorian.forward();
      this->trantorian.forward();
      this->trantorian.forward();
      this->trantorian.left();
      this->trantorian.forward();
      break;
    case 12:
      this->stackAction += 3;
      this->trantorian.forward();
      this->trantorian.forward();
      this->trantorian.forward();
      break;
    case 13:
      this->stackAction += 5;
      this->trantorian.forward();
      this->trantorian.forward();
      this->trantorian.forward();
      this->trantorian.right();
      this->trantorian.forward();
      break;
    case 14:
      this->stackAction += 6;
      this->trantorian.forward();
      this->trantorian.forward();
      this->trantorian.forward();
      this->trantorian.right();
      this->trantorian.forward();
      this->trantorian.forward();
      break;
    case 15:
      this->stackAction += 7;
      this->trantorian.forward();
      this->trantorian.forward();
      this->trantorian.forward();
      this->trantorian.right();
      this->trantorian.forward();
      this->trantorian.forward();
      this->trantorian.forward();
      break;
    default:
      this->trantorian.right();
      break;
    }
}
