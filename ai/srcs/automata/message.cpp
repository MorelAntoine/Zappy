//
// message.cpp for zappy in /mnt/d/Projects/C/PSU_2016_zappy/ai/srcs/automata
// 
// Made by DESKTOP-DHNB9O5
// Login   <antoine.morel@epitech.eu>
// 
// Started on  Tue Jun 27 14:19:32 2017 DESKTOP-DHNB9O5
// Last update Sun Jul  2 22:21:17 2017 DESKTOP-DHNB9O5
//

#include				<iostream>
#include				"automata/Automata.hpp"

void					Zappy::Ai::Automata::treatMessage(void)
{
  int32_t				idToFollow;
  std::string				cast;

  if (this->hasSameLevel() && (idToFollow = this->getIdToFollow()) != -1)
    {
      cast = this->trantorian.getArgFromMessage("-Cast");
      if (this->state > State::E3 && this->state < State::E100 && cast.size() == 0 && this->stackAction == 0)
	{
	  this->idToFollow = idToFollow;
	  this->dir = this->getDir();
	  this->state = State::E200;
	}
      else if (cast.size() > 0 && this->idToFollow == idToFollow)
	{
	  if (cast.compare("launch") == 0)
	    {
	      this->dir = this->getDir();
	      if (this->dir != 0)
		{
		  this->state = State::E0;
		  this->idToFollow = -1;
		}
	      else
		this->state = State::E201;
	    }
	  else if (cast.compare("success") == 0)
	    this->trantorian.levelUp();
	  if (cast.compare("launch") != 0)
	    {
	      this->state = State::E0;
	      this->idToFollow = -1;
	    }
	}
      else if (cast.size() > 0 && this->idToFollow == idToFollow)
	{
	  this->idToFollow = -1;
	  this->state = State::E0;
	}
      else if (this->state == State::E200 && this->idToFollow == idToFollow && cast.size() == 0 && this->stackAction == 0)
	{
	  this->dir = this->getDir();
	  if (this->dir == 0)
	    this->state = State::E201;
	}
    }
}

bool					Zappy::Ai::Automata::hasSameLevel(void)
{
  std::string				lv;
  
  lv = this->trantorian.getArgFromMessage("-Lv");
  if (lv.size() > 0)
    {
      if (std::stoi(lv) == this->trantorian.getLevel())
	return (true);
    }
  return (false);
}

int32_t					Zappy::Ai::Automata::getIdToFollow(void)
{
  std::string				idToFollow;
  
  idToFollow = this->trantorian.getArgFromMessage("-Id");
  if (idToFollow.size() > 0)
    return (std::stoi(idToFollow));
  return (-1);
}

int16_t				Zappy::Ai::Automata::getDir(void)
{
  std::string				dir;

  dir = this->trantorian.getArgFromMessage("message");
  if (dir.size() != 0)
    {
      dir.pop_back();
      return (std::stoi(dir));
    }
  return (-1);
}
