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

	int getBrGr() const;
	int getLaGr() const;
	int getBrMin() const;
	int getLaMin() const;
	double getBrSec() const;
	double getLaSec() const;

	double operator>>(const GEOKO&) const;

	~GEOKO();
};


GEOKO * dezToTime(double, double);
void timeToDez(const GEOKO *, double *, double *);
