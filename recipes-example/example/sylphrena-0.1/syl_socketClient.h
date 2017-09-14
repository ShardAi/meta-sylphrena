#ifndef SYLSOCKETCLIENT_H
#define SYLSOCKETCLIENT_H

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <syslog.h>

using namespace std;

/*
*This is a basic socket class setting up a client to send info to a server.
*/
class sylSocketClient
{
public:
	explicit sylSocketClient();
	~sylSocketClient();
    bool isConnected() { return connected; }
private:
    bool connected;
    int client;
    int server;
    int portNum;
    struct sockaddr_in server_addr;
    socklen_t size;
    int bufSize;

    //void listenForClients();
    //void listenToClient();
    //void messageReceived(const char* msg);
};

#endif //SYLSOCKETCLIENT_H

