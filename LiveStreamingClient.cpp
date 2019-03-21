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

void LiveSteamingClient::error(const int id, const int errorCode, const IBString errorString)
{
//	printf( "Error id=%d, errorCode=%d, msg=%s\n", id, errorCode, errorString.c_str());

	if( id == -1 && errorCode == 1100) // if "Connectivity between IB and TWS has been lost"
		disconnect();
}

// methods

void LiveSteamingClient::getMarketData()
{
  printf("Place Holder");
}



// Inheriting old program
void LiveSteamingClient::orderStatus( OrderId orderId, const IBString &status, int filled,
	   int remaining, double avgFillPrice, int permId, int parentId,
	   double lastFillPrice, int clientId, const IBString& whyHeld){}
void LiveSteamingClient::nextValidId( OrderId orderId) {}
void LiveSteamingClient::currentTime( long time) {}

// Required declaration
void LiveSteamingClient::tickPrice( TickerId tickerId, TickType field, double price, int canAutoExecute) {}
void LiveSteamingClient::tickSize( TickerId tickerId, TickType field, int size) {}
void LiveSteamingClient::tickOptionComputation( TickerId tickerId, TickType tickType, double impliedVol, double delta,
											 double optPrice, double pvDividend,
											 double gamma, double vega, double theta, double undPrice) {}
void LiveSteamingClient::tickGeneric(TickerId tickerId, TickType tickType, double value) {}
void LiveSteamingClient::tickString(TickerId tickerId, TickType tickType, const IBString& value) {}
void LiveSteamingClient::tickEFP(TickerId tickerId, TickType tickType, double basisPoints, const IBString& formattedBasisPoints,
							   double totalDividends, int holdDays, const IBString& futureExpiry, double dividendImpact, double dividendsToExpiry) {}
void LiveSteamingClient::openOrder( OrderId orderId, const Contract&, const Order&, const OrderState& ostate) {}
void LiveSteamingClient::openOrderEnd() {}
void LiveSteamingClient::winError( const IBString &str, int lastError) {}
void LiveSteamingClient::connectionClosed() {}
void LiveSteamingClient::updateAccountValue(const IBString& key, const IBString& val,
										  const IBString& currency, const IBString& accountName) {}
void LiveSteamingClient::updatePortfolio(const Contract& contract, int position,
		double marketPrice, double marketValue, double averageCost,
		double unrealizedPNL, double realizedPNL, const IBString& accountName){}
void LiveSteamingClient::updateAccountTime(const IBString& timeStamp) {}
void LiveSteamingClient::accountDownloadEnd(const IBString& accountName) {}
void LiveSteamingClient::contractDetails( int reqId, const ContractDetails& contractDetails) {}
void LiveSteamingClient::bondContractDetails( int reqId, const ContractDetails& contractDetails) {}
void LiveSteamingClient::contractDetailsEnd( int reqId) {}
void LiveSteamingClient::execDetails( int reqId, const Contract& contract, const Execution& execution) {}
void LiveSteamingClient::execDetailsEnd( int reqId) {}

void LiveSteamingClient::updateMktDepth(TickerId id, int position, int operation, int side,
									  double price, int size) {}
void LiveSteamingClient::updateMktDepthL2(TickerId id, int position, IBString marketMaker, int operation,
										int side, double price, int size) {}
void LiveSteamingClient::updateNewsBulletin(int msgId, int msgType, const IBString& newsMessage, const IBString& originExch) {}
void LiveSteamingClient::managedAccounts( const IBString& accountsList) {}
void LiveSteamingClient::receiveFA(faDataType pFaDataType, const IBString& cxml) {}
void LiveSteamingClient::historicalData(TickerId reqId, const IBString& date, double open, double high,
									  double low, double close, int volume, int barCount, double WAP, int hasGaps) {}
void LiveSteamingClient::scannerParameters(const IBString &xml) {}
void LiveSteamingClient::scannerData(int reqId, int rank, const ContractDetails &contractDetails,
	   const IBString &distance, const IBString &benchmark, const IBString &projection,
	   const IBString &legsStr) {}
void LiveSteamingClient::scannerDataEnd(int reqId) {}
void LiveSteamingClient::realtimeBar(TickerId reqId, long time, double open, double high, double low, double close,
								   long volume, double wap, int count) {}
void LiveSteamingClient::fundamentalData(TickerId reqId, const IBString& data) {}
void LiveSteamingClient::deltaNeutralValidation(int reqId, const UnderComp& underComp) {}
void LiveSteamingClient::tickSnapshotEnd(int reqId) {}
void LiveSteamingClient::marketDataType(TickerId reqId, int marketDataType) {}
void LiveSteamingClient::commissionReport( const CommissionReport& commissionReport) {}
void LiveSteamingClient::position( const IBString& account, const Contract& contract, int position, double avgCost) {}
void LiveSteamingClient::positionEnd() {}
void LiveSteamingClient::accountSummary( int reqId, const IBString& account, const IBString& tag, const IBString& value, const IBString& curency) {}
void LiveSteamingClient::accountSummaryEnd( int reqId) {}
void LiveSteamingClient::verifyMessageAPI( const IBString& apiData) {}
void LiveSteamingClient::verifyCompleted( bool isSuccessful, const IBString& errorText) {}
void LiveSteamingClient::displayGroupList( int reqId, const IBString& groups) {}
void LiveSteamingClient::displayGroupUpdated( int reqId, const IBString& contractInfo) {}
