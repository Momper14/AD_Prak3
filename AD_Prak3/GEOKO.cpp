#include "GEOKO.h"

GEOKO::GEOKO(int brGr, int laGr, int brMin, int laMin, double brSec, double laSec, GEOKO *v, GEOKO *n):DVKE(v, n){
	this->brGr = brGr;
	this->laGr = laGr;
	this->brMin = brMin;
	this->laMin = laMin;
	this->brSec = brSec;
	this->laSec = laSec;
}

GEOKO::GEOKO(int brGr, int laGr, int brMin, int laMin, double brSec, double laSec) :GEOKO(brGr, laGr, brMin, laMin, brSec, laSec, nullptr, nullptr){
}

GEOKO::~GEOKO(){
}
