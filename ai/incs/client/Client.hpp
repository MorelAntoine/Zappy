//
// Client.hpp for zappy in /mnt/d/Projects/C/PSU_2016_zappy/ai/srcs
// 
// Made by DESKTOP-DHNB9O5
// Login   <antoine.morel@epitech.eu>
// 
// Started on  Wed Jun 14 16:03:13 2017 DESKTOP-DHNB9O5
// Last update Tue Jun 27 13:52:27 2017 DESKTOP-DHNB9O5
//

#ifndef					CLIENT_HPP_
#define					CLIENT_HPP_

#include				<cstdint>
#include				<string>

namespace Zappy
{
  namespace Ai
  {
    class Client
    {      
    public:
      static const int8_t		SOCKET_DEFAULT = -1;
      static const int8_t		SOCKET_ERROR = -1;
      static const uint16_t		BUFF_SIZE = 4096;
      static constexpr const char	*LF = "\n";

    private:
      int32_t				sock;
      uint16_t				port;
      std::string			addr;
      std::string			response;

    public:
      Client(void);
      ~Client(void);

    public:
      int32_t				getSock(void) const;
      uint16_t				getPort(void) const;
      void				setPort(const uint16_t src);
      std::string			getAddr(void) const;
      void				setAddr(const std::string &src);
      void				clearResponseBuffer(void);

    public:
      bool				connect(const uint16_t port, const std::string &addr, const std::string &team);
      bool				close(void);
      bool				send(const std::string &data) const;
      const std::string			&getResponse(void);
      std::string			getCurrentResponse(void);
      void				nextResponse(void);

    private:
      bool				createSocket(const std::string &protoname);
      bool				connectSocket(const uint16_t port, const std::string &addr);
    };
  }
}

#endif					/* !CLIENT_HPP_ */
