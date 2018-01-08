#pragma once
#include "DVKE.h"
class GEOKO :
	public DVKE{
private:
	int brGr, laGr, brMin, laMin;
	double brSec, laSec;
public:
	GEOKO(int, int, int, int, double, double, GEOKO*, GEOKO*);
	GEOKO(int, int, int, int, double, double, GEOKO*);
	GEOKO(int, int, int, int, double, double);

	int getBrGr();
	int getLaGr();
	int getBrMin();
	int getLaMin();
	double getBrSec();
	double getLaSec();

	~GEOKO();
};

