#ifdef _WIN32
# include <Windows.h>
# define sleep( seconds) Sleep( seconds * 1000);
#else
# include <unistd.h>
#endif

// Time printer
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

// Print timestamp
#include <ctime>

// for application use
#include "LiveStreamingClient.h"

const unsigned MAX_ATTEMPTS = 50;
const unsigned SLEEP_TIME = 10;

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

int main(int argc, char** argv)
{
	const char* host = argc > 1 ? argv[1] : "";
        unsigned int port = 4002;
	//	unsigned int port = 7496;
	int clientId = 0;
	unsigned attempt = 0;
  printf( "Start of Live Streaming Socket Client Test %u\n", attempt);

	for (;;) {
		++attempt;
		printf( "Attempt %u of %u\n", attempt, MAX_ATTEMPTS);

		LiveSteamingClient client;

		client.connect( host, port, clientId);
    client.getMarketData();
    
		while( client.isConnected()) {
      // Print time first
			printf(currentDateTime().c_str());
      std::time_t t = std::time(0);
      std::cout << "-timestamp:" << t << "\n";
      // temp setup to break the loop
      return 0;
		}

		if( attempt >= MAX_ATTEMPTS) {
			break;
		}

		printf( "Sleeping %u seconds before next attempt\n", SLEEP_TIME);
		sleep( SLEEP_TIME);
	}

  	printf ( "End of POSIX Socket Client Test\n");
}
