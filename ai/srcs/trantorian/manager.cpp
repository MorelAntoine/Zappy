//
// manager.cpp for zappy in /mnt/d/Projects/C/PSU_2016_zappy/ai/srcs/client
// 
// Made by DESKTOP-DHNB9O5
// Login   <antoine.morel@epitech.eu>
// 
// Started on  Tue Jun 27 13:58:22 2017 DESKTOP-DHNB9O5
// Last update Wed Jun 28 15:11:20 2017 DESKTOP-DHNB9O5
//

#include				<cstdlib>
#include				"trantorian/Trantorian.hpp"

Zappy::Ai::Trantorian::Trantorian(const std::string &_team, Zappy::Ai::Client *_client)
  : alive(true), team(_team), level(1), client(), id(std::rand())
{
  this->client = _client;
}

Zappy::Ai::Trantorian::~Trantorian(void)
{}

bool					Zappy::Ai::Trantorian::isAlive(void) const
{ return (this->alive); }

void					Zappy::Ai::Trantorian::setAlive(const bool status)
{ this->alive = status; }

std::string				Zappy::Ai::Trantorian::getTeam(void) const
{ return (this->team); }

uint16_t				Zappy::Ai::Trantorian::getLevel(void) const
{ return (this->level); }

void					Zappy::Ai::Trantorian::levelUp(void)
{ this->level++; }

Zappy::Ai::Client                       *Zappy::Ai::Trantorian::getClient(void)
{ return (this->client); }

int32_t					Zappy::Ai::Trantorian::getId(void) const
{ return (this->id); }
