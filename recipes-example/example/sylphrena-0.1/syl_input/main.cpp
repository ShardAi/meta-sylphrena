#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include "syl_socketClient.h"

using namespace std;

#define DAEMON_NAME "sylInputDaemon"

/*void process()
{
	syslog(LOG_NOTICE, "Writing to Sylphrenas Syslog");
}*/

int main(int argc, char *argv[])
{
	cout << "-----------Starting application to send input to Sylphrena-------------" << endl;
	/*
	//Set our logging mask and open log
	setlogmask(LOG_UPTO (LOG_NOTICE));
	openlog("testd", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);

	process();

	syslog(LOG_INFO, "Entering Daemon");

	pid_t pid, sid;

	//Fork the parent process
	pid = fork();

	if (pid < 0) { exit(EXIT_FAILURE); }

	//We got a good pid, Close the Parent Process
	if (pid > 0) { exit(EXIT_SUCCESS); }

	//Change File Mask
	umask(0);

	//Create a new Signature Id for our child
	sid = setsid();
	if (sid < 0) { exit(EXIT_FAILURE); }

	//Change Directory
	//If we cant find the directory we exit with failure.
	if ((chdir("/")) < 0) { exit(EXIT_FAILURE); }

	//Close Standard File Descriptors
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	//sylCore *core = new sylCore();

	//----------------
	//Main Process
	//----------------
	while(true)
    {
		process();    //Run our Process
		sleep(60);    //Sleep for 60 seconds
	}

	delete core;

	closelog();*/

	return 0;
}

