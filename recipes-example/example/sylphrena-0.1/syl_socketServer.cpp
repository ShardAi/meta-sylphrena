#include "syl_socketServer.h"

sylSocketServer::sylSocketServer()
{
    portNum = 1500;
    connected = false;
    bufSize = 1024;


    //init socket
    client = socket(AF_INET, SOCK_STREAM, 0);

    if(client < 0)
    {
        //TODO: Make syslog error and exit program.
        connected = false;
        return;
    }

    connected = true;

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDER_ANY);
    server_addr.sin_port = htons(portNum);

    if(bind(client, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        connected = false;
        return;
    }

    size = sizeof(server_addr);

    while(true)
    {
        listenForClients();
        if(!connected)
            sleep(60);
    }
    close(client);
}

sylSocketServer::~sylSocketServer()
{
    if(server >= 0)
        close(server);
    if(client >= 0)
        close(client);
}

void sylSocketServer::listenForClients()
{
    //listening socket
    listen(client, 1);

    //accept client
    server = accept(client, (struct sockaddr*)&server_addr, &size);

    if(server < 0)
    {
        connected = false;
        return;
    }

    connected = true;

    listenToClient();
}

void sylSocketServer::listenToClient()
{

    char buffer[bufSize];
    bool isExit = false;

    while(server > 0)
    {
        strcpy(buffer, "Server connected...\n");
        send(server, buffer, bufSize);

        //Connected with client
        //Enter # to end the connection

        //Client:
        do
        {
            recv(server, buffer, bufSize, 0);
            messageReceived(buffer);
            if(*buffer == '#')
            {
                *buffer = '*';
                isExit = true;
            }
        } while(*buffer != '*');

        close(server);
        connected = false;
    }
}

void messageReceived(const char *msg)
{
    syslog(LOG_INFO, "sys_socketServer: Message received:" + msg);
}

