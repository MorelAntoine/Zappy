//
// commands.cpp for zappy in /mnt/d/Projects/C/PSU_2016_zappy/ai/srcs/client
// 
// Made by DESKTOP-DHNB9O5
// Login   <antoine.morel@epitech.eu>
// 
// Started on  Tue Jun 27 13:58:31 2017 DESKTOP-DHNB9O5
// Last update Sun Jul  2 23:27:10 2017 DESKTOP-DHNB9O5
//

#include				"trantorian/Trantorian.hpp"

bool					Zappy::Ai::Trantorian::forward(void) const
{
  return (this->client->send("Forward"));
}

bool					Zappy::Ai::Trantorian::right(void) const
{
  return (this->client->send("Right"));
}

bool					Zappy::Ai::Trantorian::left(void) const
{
  return (this->client->send("Left"));
}

bool					Zappy::Ai::Trantorian::look(void) const
{
  return (this->client->send("Look"));
}

bool					Zappy::Ai::Trantorian::inventory(void) const
{
  return (this->client->send("Inventory"));
}

bool					Zappy::Ai::Trantorian::broadcast(const std::string &text) const
{
  return (this->client->send("Broadcast " + text));
}

bool					Zappy::Ai::Trantorian::connectNbr(void) const
{
  return (this->client->send("Connect_nbr"));
}

bool					Zappy::Ai::Trantorian::fork(void) const
{
  return (this->client->send("Fork"));
}

bool					Zappy::Ai::Trantorian::eject(void) const
{ return (this->client->send("Eject")); }

bool					Zappy::Ai::Trantorian::take(const std::string &object) const
{
  return (this->client->send("Take " + object));
}

bool					Zappy::Ai::Trantorian::set(const std::string &object) const
{
  return (this->client->send("Set " + object));
}

bool					Zappy::Ai::Trantorian::incantation(void) const
{
  return (this->client->send("Incantation"));
}
