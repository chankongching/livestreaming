#ifndef livesteamingclient_h__INCLUDED
#define livesteamingclient_h__INCLUDED

#include "EWrapper.h"

#include <memory>

class EPosixClientSocket;

class LiveSteamingClient : public EWrapper
{
public:
  LiveSteamingClient();
  ~LiveSteamingClient();
  void getMarketData();

public:
	bool connect(const char * host, unsigned int port, int clientId = 0);
	void disconnect() const;
	bool isConnected() const;
};
#endif
