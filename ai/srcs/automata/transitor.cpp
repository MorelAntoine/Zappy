//
// transitor.cpp for zappy in /mnt/d/Projects/C/PSU_2016_zappy/ai/srcs/automata
// 
// Made by DESKTOP-DHNB9O5
// Login   <antoine.morel@epitech.eu>
// 
// Started on  Tue Jun 27 14:19:42 2017 DESKTOP-DHNB9O5
// Last update Sun Jul  2 23:30:29 2017 DESKTOP-DHNB9O5
//

#include				<cstring>
#include				<iostream>
#include				<sstream>
#include				"automata/Automata.hpp"

void					Zappy::Ai::Automata::transitor(void)
{
  if (this->stackAction == 0)
    {
      if (this->state < State::E100)
	this->collectTransitor();
      else if (this->state < State::E200)
	this->castTransitor();
    }
}

void					Zappy::Ai::Automata::collectTransitor(void)
{
  switch (this->state)
    {
    case State::E0: // needFood
      this->objToCollect = "food";
      if (this->trantorian.getFromInventoryTheValueOf(this->objToCollect) < MAX_FOOD)
	this->state = State::E1;
      else
	this->state = State::E4;
      break;
    case State::E1: // onCase
      if (this->trantorian.onCase(this->objToCollect) && this->trantorian.isAloneOnCase())
	this->state = State::E3;
      else
	{
	  this->caseToGo = this->getCaseToGoFromLook();
	  this->state = State::E2;
	}
      break;
    case State::E2: // move
      this->state = State::E1;
      break;
    case State::E3: // take
      this->state = State::E0;
      break;
    case State::E4: // needStone
      this->objToCollect = this->trantorian.getRequireStone();
      if (this->objToCollect.size() == 0)
	this->state = State::E100;
      else
	this->state = State::E5;
      break;
    case State::E5: // onCase
      if (this->trantorian.onCase(this->objToCollect) && this->trantorian.isAloneOnCase())
	this->state = State::E7;
      else
	{
	  this->caseToGo = this->getCaseToGoFromLook();
	  this->state = State::E6;
	}
      break;
    case State::E6: // move
      this->state = State::E5;
      break;
    case State::E7: // take
      this->state = State::E0;
      break;
    default:
      break;
    }
}

void					Zappy::Ai::Automata::castTransitor(void)
{
  switch (this->state)
    {
    case State::E100: // needPers
      if (this->trantorian.enoughPersOnCase())
	{
	  if (this->trantorian.getLevel() != 1)
	    this->state = State::E102;
	  else
	    this->state = State::E103;
	}
      else
	this->state = State::E120;
      break;
    case State::E120: // critFood
      if (this->trantorian.getFromInventoryTheValueOf("food") <= CRIT_FOOD)
	this->state = State::E121;
      else
	this->state = State::E101;
      break;
    case State::E121: // callBreak
      this->state = State::E0;
      break;
    case State::E101: // call
      this->state = State::E100;
      break;
    case State::E102: // callCast
      this->state = State::E103;
      break;
    case State::E103: // needToClean
      this->objToCollect = this->trantorian.popElemOnCase();
      if (this->objToCollect.size() == 0)
	this->state = State::E105;
      else
	this->state = State::E104;
      break;
    case State::E104: // clear
      this->state = State::E103;
      break;
    case State::E105: // stonesOnCase
      this->objToSet = this->trantorian.stoneToSet();
      if (this->objToSet.size() == 0)
	this->state = State::E107;
      else
	this->state = State::E106;
      break;
    case State::E106: // set
      this->state = State::E105;
      break;
    case State::E107: // cast
      this->endCastStatus = "fail";
      this->trantorian.getClient()->getCurrentResponse();
      if (this->trantorian.getClient()->getCurrentResponse().compare("ko") != 0)
	this->endCastStatus = "success";
      this->state = State::E108;
      break;
    case State::E108: // callEndCast
      this->state = State::E0;
      break;
    default:
      break;
    }
}
