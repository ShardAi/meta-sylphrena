/*!
 * Sylphrena AI core program - https://github.com/ShardAi
 * Version - 1.0.0.0
 *
 * Copyright (c) 2017 Eirik Skjeggestad Dale
 */

#ifndef SYLCORE_H
#define SYLCORE_H

#include <stdlib.h>
#include <iostream>
#include <syslog.h>
#include "syl_socketServer.h"

using namespace std;

class sylCore
{
public:
	explicit sylCore();
	~sylCore();

	void counterMethod();
	void start();

private:
	int counter;
	sylSocketServer *server;
};

#endif //SYLCORE_H
