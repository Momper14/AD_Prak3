#pragma once
#define MAXELE 1000000

#include "GEOKO.h"
#include "cstring"

using namespace std;

class DVK{
private:
	GEOKO *anker_V, *anker_R, *middle, **index;
	int anz;
public:
	DVK(int anzahl, char name[]);
	~DVK();
};

