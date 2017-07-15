//
// tools.cpp for zappy in /mnt/d/Projects/C/PSU_2016_zappy/ai/srcs/client
// 
// Made by DESKTOP-DHNB9O5
// Login   <antoine.morel@epitech.eu>
// 
// Started on  Tue Jun 27 13:58:43 2017 DESKTOP-DHNB9O5
// Last update Sun Jul  2 12:36:58 2017 DESKTOP-DHNB9O5
//

#include				<iostream>
#include				<cstdlib>
#include				<cstring>
#include				"trantorian/Trantorian.hpp"

uint16_t				Zappy::Ai::Trantorian::getFromInventoryTheValueOf(const std::string &object)
{
  std::string				responseCopy(this->getClient()->getCurrentResponse());
  char					*token;
  int32_t				value(0);

  token = std::strtok(const_cast<char *>(responseCopy.c_str()), " ");
  while (token && std::strcmp(token, object.c_str()) != 0)
    token = std::strtok(NULL, " ");
  if (token && std::strcmp(token, object.c_str()) == 0)
    value = std::atoi(std::strtok(NULL, " "));
  return (value);
}

bool					Zappy::Ai::Trantorian::onCase(const std::string &object)
{
  std::string				responseCopy(this->getClient()->getCurrentResponse());
  char					*ref;
  char					*token;

  ref = std::strtok(const_cast<char *>(responseCopy.c_str()), ",");
  if (!ref)
    return (false);
  token = std::strtok(ref, " ");
  while (token && std::strcmp(token, object.c_str()) != 0)
    token = std::strtok(NULL, " ");
  return ((token ? true : false));
}

std::string				Zappy::Ai::Trantorian::getArgFromMessage(const std::string &flag)
{
  std::string				responseCopy(this->getClient()->getCurrentResponse());
  char					*token;
  bool					hasFlag(false);

  token = std::strtok(const_cast<char *>(responseCopy.c_str()), " ");
  while (token)
    {
      if (hasFlag)
	return (token);
      if (std::strcmp(token, flag.c_str()) == 0)
	hasFlag = true;
      token = std::strtok(NULL, " ");
    }
  return ("");
}

std::string				Zappy::Ai::Trantorian::popElemOnCase(void)
{
  std::string				responseCopy(this->getClient()->getCurrentResponse());
  char                                 *ref;
  char                                 *token;

  ref = std::strtok(const_cast<char *>(responseCopy.c_str()), ",");
  token = std::strtok(ref, " ");
  token = std::strtok(NULL, " ");
  while (token)
    {
      if (std::strcmp(token, "player") != 0)
	return (token);
      token = std::strtok(NULL, " ");
    }
  return ("");
}

bool					Zappy::Ai::Trantorian::isAloneOnCase(void)
{
  std::string				responseCopy(this->getClient()->getCurrentResponse());
  char					*ref;
  char					*token;
  uint16_t				cpt(0);

  ref = std::strtok(const_cast<char *>(responseCopy.c_str()), ",");
  token = std::strtok(ref, " ");
  token = std::strtok(NULL, " ");
  while (token)
    {
      if (cpt > 1)
	return (false);
      if (std::strcmp(token, "player") == 0)
	cpt++;
      token = std::strtok(NULL, " ");
    }
  return (true);
}

uint32_t				Zappy::Ai::Trantorian::onCaseCount(const std::string &obj)
{
  std::string                           responseCopy(this->getClient()->getCurrentResponse());
  char                                  *ref;
  char                                  *token;
  uint16_t                              cpt(0);

  ref = std::strtok(const_cast<char *>(responseCopy.c_str()), ",");
  token = std::strtok(ref, " ");
  token = std::strtok(NULL, " ");
  while (token)
    {
      if (std::strcmp(token, obj.c_str()) == 0)
	cpt++;
      token = std::strtok(NULL, " ");
    }
  return (cpt);
}

std::string				Zappy::Ai::Trantorian::getRequireStone(void)
{
  uint16_t				bag[6];

  bag[0] = this->getFromInventoryTheValueOf("linemate");
  bag[1] = this->getFromInventoryTheValueOf("deraumere");
  bag[2] = this->getFromInventoryTheValueOf("sibur");
  bag[3] = this->getFromInventoryTheValueOf("mendiane");
  bag[4] = this->getFromInventoryTheValueOf("phiras");
  bag[5] = this->getFromInventoryTheValueOf("thystame");
  if (this->ELEVATION_SECRET[this->level - 1][ElevIdx::LINEMATE] > bag[0])
    return ("linemate");
  if (this->ELEVATION_SECRET[this->level - 1][ElevIdx::DERAUMERE] > bag[1])
    return ("deraumere");
  if (this->ELEVATION_SECRET[this->level - 1][ElevIdx::SIBUR] > bag[2])
    return ("sibur");
  if (this->ELEVATION_SECRET[this->level - 1][ElevIdx::MENDIANE] > bag[3])
    return ("mendiane");
  if (this->ELEVATION_SECRET[this->level - 1][ElevIdx::PHIRAS] > bag[4])
    return ("phiras");
  if (this->ELEVATION_SECRET[this->level - 1][ElevIdx::THYSTAME] > bag[5])
    return ("thystame");
  return ("");
}

bool					Zappy::Ai::Trantorian::enoughPersOnCase(void)
{
  if (this->ELEVATION_SECRET[this->level - 1][ElevIdx::NB_PERS] > this->onCaseCount("player"))
    return (false);
  return (true);
}

std::string				Zappy::Ai::Trantorian::stoneToSet(void)
{
  uint16_t				stone[6];

  stone[0] = this->onCaseCount("linemate");
  stone[1] = this->onCaseCount("deraumere");
  stone[2] = this->onCaseCount("sibur");
  stone[3] = this->onCaseCount("mendiane");
  stone[4] = this->onCaseCount("phiras");
  stone[5] = this->onCaseCount("thystame");
  if (this->ELEVATION_SECRET[this->level - 1][ElevIdx::LINEMATE] > stone[0])
    return ("linemate");
  if (this->ELEVATION_SECRET[this->level - 1][ElevIdx::DERAUMERE] > stone[1])
    return ("deraumere");
  if (this->ELEVATION_SECRET[this->level - 1][ElevIdx::SIBUR] > stone[2])
    return ("sibur");
  if (this->ELEVATION_SECRET[this->level - 1][ElevIdx::MENDIANE] > stone[3])
    return ("mendiane");
  if (this->ELEVATION_SECRET[this->level - 1][ElevIdx::PHIRAS] > stone[4])
    return ("phiras");
  if (this->ELEVATION_SECRET[this->level - 1][ElevIdx::THYSTAME] > stone[5])
    return ("thystame");
  return ("");
}
