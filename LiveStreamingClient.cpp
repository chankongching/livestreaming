#include "LiveStreamingClient.h"

#include "EPosixClientSocket.h"
#include "EPosixClientSocketPlatform.h"

const int PING_DEADLINE = 2; // seconds
const int SLEEP_BETWEEN_PINGS = 30; // seconds

// member funcs
LiveSteamingClient::LiveSteamingClient()
	: m_pClient(new EPosixClientSocket(this))
	, m_state(ST_CONNECT)
	, m_sleepDeadline(0)
	, m_orderId(0)
{
}

LiveSteamingClient::~LiveSteamingClient()
{
}

void LiveSteamingClient::getMarketData()
{
  printf("Place Holder");
}

bool LiveSteamingClient::connect(const char *host, unsigned int port, int clientId)
{
	// trying to connect
	printf( "Connecting to %s:%d clientId:%d\n", !( host && *host) ? "127.0.0.1" : host, port, clientId);

	bool bRes = m_pClient->eConnect( host, port, clientId, /* extraAuth */ false);

	if (bRes) {
		printf( "Connected to %s:%d clientId:%d\n", !( host && *host) ? "127.0.0.1" : host, port, clientId);
	}
	else
		printf( "Cannot connect to %s:%d clientId:%d\n", !( host && *host) ? "127.0.0.1" : host, port, clientId);

	return bRes;
}

void LiveSteamingClient::disconnect() const
{
	m_pClient->eDisconnect();

	printf ( "Disconnected\n");
}

bool LiveSteamingClient::isConnected() const
{
	return m_pClient->isConnected();
}
