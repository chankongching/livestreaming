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

// methods

void LiveSteamingClient::getMarketData()
{
  printf("Place Holder");
}

// Required declaration
void PosixTestClient::tickPrice( TickerId tickerId, TickType field, double price, int canAutoExecute) {}
void PosixTestClient::tickSize( TickerId tickerId, TickType field, int size) {}
void PosixTestClient::tickOptionComputation( TickerId tickerId, TickType tickType, double impliedVol, double delta,
											 double optPrice, double pvDividend,
											 double gamma, double vega, double theta, double undPrice) {}
void PosixTestClient::tickGeneric(TickerId tickerId, TickType tickType, double value) {}
void PosixTestClient::tickString(TickerId tickerId, TickType tickType, const IBString& value) {}
void PosixTestClient::tickEFP(TickerId tickerId, TickType tickType, double basisPoints, const IBString& formattedBasisPoints,
							   double totalDividends, int holdDays, const IBString& futureExpiry, double dividendImpact, double dividendsToExpiry) {}
void PosixTestClient::openOrder( OrderId orderId, const Contract&, const Order&, const OrderState& ostate) {}
void PosixTestClient::openOrderEnd() {}
void PosixTestClient::winError( const IBString &str, int lastError) {}
void PosixTestClient::connectionClosed() {}
void PosixTestClient::updateAccountValue(const IBString& key, const IBString& val,
										  const IBString& currency, const IBString& accountName) {}
void PosixTestClient::updatePortfolio(const Contract& contract, int position,
		double marketPrice, double marketValue, double averageCost,
		double unrealizedPNL, double realizedPNL, const IBString& accountName){}
void PosixTestClient::updateAccountTime(const IBString& timeStamp) {}
void PosixTestClient::accountDownloadEnd(const IBString& accountName) {}
void PosixTestClient::contractDetails( int reqId, const ContractDetails& contractDetails) {}
void PosixTestClient::bondContractDetails( int reqId, const ContractDetails& contractDetails) {}
void PosixTestClient::contractDetailsEnd( int reqId) {}
void PosixTestClient::execDetails( int reqId, const Contract& contract, const Execution& execution) {}
void PosixTestClient::execDetailsEnd( int reqId) {}

void PosixTestClient::updateMktDepth(TickerId id, int position, int operation, int side,
									  double price, int size) {}
void PosixTestClient::updateMktDepthL2(TickerId id, int position, IBString marketMaker, int operation,
										int side, double price, int size) {}
void PosixTestClient::updateNewsBulletin(int msgId, int msgType, const IBString& newsMessage, const IBString& originExch) {}
void PosixTestClient::managedAccounts( const IBString& accountsList) {}
void PosixTestClient::receiveFA(faDataType pFaDataType, const IBString& cxml) {}
void PosixTestClient::historicalData(TickerId reqId, const IBString& date, double open, double high,
									  double low, double close, int volume, int barCount, double WAP, int hasGaps) {}
void PosixTestClient::scannerParameters(const IBString &xml) {}
void PosixTestClient::scannerData(int reqId, int rank, const ContractDetails &contractDetails,
	   const IBString &distance, const IBString &benchmark, const IBString &projection,
	   const IBString &legsStr) {}
void PosixTestClient::scannerDataEnd(int reqId) {}
void PosixTestClient::realtimeBar(TickerId reqId, long time, double open, double high, double low, double close,
								   long volume, double wap, int count) {}
void PosixTestClient::fundamentalData(TickerId reqId, const IBString& data) {}
void PosixTestClient::deltaNeutralValidation(int reqId, const UnderComp& underComp) {}
void PosixTestClient::tickSnapshotEnd(int reqId) {}
void PosixTestClient::marketDataType(TickerId reqId, int marketDataType) {}
void PosixTestClient::commissionReport( const CommissionReport& commissionReport) {}
void PosixTestClient::position( const IBString& account, const Contract& contract, int position, double avgCost) {}
void PosixTestClient::positionEnd() {}
void PosixTestClient::accountSummary( int reqId, const IBString& account, const IBString& tag, const IBString& value, const IBString& curency) {}
void PosixTestClient::accountSummaryEnd( int reqId) {}
void PosixTestClient::verifyMessageAPI( const IBString& apiData) {}
void PosixTestClient::verifyCompleted( bool isSuccessful, const IBString& errorText) {}
void PosixTestClient::displayGroupList( int reqId, const IBString& groups) {}
void PosixTestClient::displayGroupUpdated( int reqId, const IBString& contractInfo) {}
