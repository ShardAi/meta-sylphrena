/*!
 * Sylphrena AI core program - https://github.com/ShardAi
 * Version - 1.0.0.0
 *
 * Copyright (c) 2017 Eirik Skjeggestad Dale
 */

#include "syl_core.h"

sylCore::sylCore()
{
	counter = 0;
}

sylCore::~sylCore()
{
    delete server;
}

void sylCore::start()
{
	server = new sylSocketServer();
}

void sylCore::counterMethod()
{
	counter++;
}
