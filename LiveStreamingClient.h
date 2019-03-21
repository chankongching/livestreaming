#ifndef livesteamingclient_h__INCLUDED
#define livesteamingclient_h__INCLUDED

#include "EWrapper.h"

#include <memory>

class EPosixClientSocket;

enum State {
	ST_CONNECT,
	ST_PLACEORDER,
	ST_PLACEORDER_ACK,
	ST_CANCELORDER,
	ST_CANCELORDER_ACK,
	ST_PING,
	ST_PING_ACK,
	ST_IDLE
};

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

private:

  std::auto_ptr<EPosixClientSocket> m_pClient;
	State m_state;
	time_t m_sleepDeadline;

	OrderId m_orderId;
};
#endif
