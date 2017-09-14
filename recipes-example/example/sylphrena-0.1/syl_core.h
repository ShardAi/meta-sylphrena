#ifndef SYLCORE_H
#define SYLCORE_H

#include <stdlib.h>
#include <iostream>
#include <syslog.h>

using namespace std;

class sylCore
{
public:
	explicit sylCore();
	~sylCore();

	void counterMethod();

private:
	int counter;
};

#endif //SYLCORE_H
