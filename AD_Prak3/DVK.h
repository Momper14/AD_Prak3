#pragma once
#define MAXELE 1000000

#include "GEOKO.h"
#include "string"

using namespace std;

class DVK{
private:
	GEOKO * anker_V, *anker_R, *middle, *index[MAXELE];
	int anz;
public:
	DVK(int, string);

	void middleNew();

	~DVK();
};

