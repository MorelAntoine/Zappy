//
// manager.cpp for zappy in /mnt/d/Projects/C/PSU_2016_zappy/ai/srcs/automata
// 
// Made by DESKTOP-DHNB9O5
// Login   <antoine.morel@epitech.eu>
// 
// Started on  Tue Jun 27 14:19:09 2017 DESKTOP-DHNB9O5
// Last update Sun Jul  2 23:26:15 2017 DESKTOP-DHNB9O5
//

#include				<iostream>
#include				<cstring>
#include				<cstring>
#include				"automata/Automata.hpp"

Zappy::Ai::Automata::Automata(Zappy::Ai::Trantorian &_trantorian)
  : trantorian(_trantorian), state(Zappy::Ai::Automata::State::E0),
    objToCollect(""), objToSet(""), dir(-1), idToFollow(-1), endCastStatus(""),
    stackAction(0), caseToGo(0)
{}

Zappy::Ai::Automata::~Automata(void)
{}

void					Zappy::Ai::Automata::run(void)
{
  this->trantorian.getClient()->clearResponseBuffer();
  while (this->trantorian.isAlive())
    {
      this->request();
      this->trantorian.getClient()->getResponse();
      while (this->state == State::E107
	     && this->trantorian.getClient()->getCurrentResponse().find("level:") == std::string::npos
	     && this->trantorian.getClient()->getCurrentResponse().find("ko") == std::string::npos)
	{
	  if (this->trantorian.getClient()->getCurrentResponse().compare("dead") == 0)
	    {
	      this->trantorian.setAlive(false);
	      break;
	    }
	  this->trantorian.getClient()->nextResponse();
	  if (this->trantorian.getClient()->getCurrentResponse().size() == 0)
	    this->trantorian.getClient()->getResponse();
	}
      while (this->state == State::E0 && this->trantorian.getClient()->getCurrentResponse().find("food") == std::string::npos)
	{
	  if (this->trantorian.getClient()->getCurrentResponse().compare("dead") == 0)
	    {
	      this->trantorian.setAlive(false);
	      break;
	    }
	  this->trantorian.getClient()->nextResponse();
	  if (this->trantorian.getClient()->getCurrentResponse().size() == 0)
	    this->trantorian.getClient()->getResponse();
	}
      if (this->stackAction == 0)
	this->stackAction++;
      while (this->stackAction > 0)
	{
	  this->stackAction--;
	  while (this->trantorian.getClient()->getCurrentResponse().substr(0, 7).compare("message") == 0)
	    {
	      this->treatMessage();
	      this->trantorian.getClient()->nextResponse();
	      if (this->trantorian.getClient()->getCurrentResponse().size() == 0)
		this->trantorian.getClient()->getResponse();
	    }
	  if (this->trantorian.getClient()->getCurrentResponse().compare("dead") == 0)
	    this->trantorian.setAlive(false);
	  else
	    this->transitor();
	  this->trantorian.getClient()->nextResponse();
	  if (this->trantorian.getClient()->getCurrentResponse().size() == 0 && this->stackAction > 0 && this->trantorian.isAlive())
	    this->trantorian.getClient()->getResponse();
	}
    }
}

uint16_t				Zappy::Ai::Automata::getCaseToGoFromLook(void)
{
  uint16_t				caseToGo(0);
  std::string				responseCopy(this->trantorian.getClient()->getCurrentResponse());
  char					*ref;
  char					*token;
  char					*tmp;
  bool					playerOnCase;
  bool					find;

  if ((tmp = strdup(responseCopy.c_str())) == NULL)
    return (2);
  ref = std::strtok(tmp, ",");
  while (ref)
    {
      playerOnCase = false;
      find = false;
      token = std::strtok(ref, " ");
      while (token)
	{
	  if (std::strcmp(token, this->objToCollect.c_str()) == 0)
	    find = true;
	  if (std::strcmp(token, "player") == 0)
	    playerOnCase = true;
	  token = std::strtok(NULL, " ");
	}
      if (tmp)
	free(tmp);
      if (find && !playerOnCase)
	return (caseToGo);
      caseToGo++;
      if (responseCopy.find(",") == std::string::npos)
	return (2);
      responseCopy = responseCopy.substr(responseCopy.find(",") + 1);
      if ((tmp = strdup(responseCopy.c_str())) == NULL)
	return (2);
      ref = std::strtok(tmp, ",");
    }
  return (2);
}
