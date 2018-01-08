#include "GEOKO.h"

GEOKO::GEOKO(int brGr, int laGr, int brMin, int laMin, double brSec, double laSec, GEOKO *v, GEOKO *n):DVKE(v, n){
	this->brGr = brGr;
	this->laGr = laGr;
	this->brMin = brMin;
	this->laMin = laMin;
	this->brSec = brSec;
	this->laSec = laSec;
}

GEOKO::GEOKO(int brGr, int laGr, int brMin, int laMin, double brSec, double laSec, GEOKO *v) :GEOKO(brGr, laGr, brMin, laMin, brSec, laSec, v, nullptr){
}

GEOKO::GEOKO(int brGr, int laGr, int brMin, int laMin, double brSec, double laSec) :GEOKO(brGr, laGr, brMin, laMin, brSec, laSec, nullptr){
}

int GEOKO::getBrGr(){
	return this->brGr;
}

int GEOKO::getLaGr(){
	return this->laGr;
}

int GEOKO::getBrMin(){
	return this->brMin;
}

int GEOKO::getLaMin(){
	return this->laMin;
}

double GEOKO::getBrSec(){
	return this->brSec;
}

double GEOKO::getLaSec(){
	return this->laSec;
}

GEOKO::~GEOKO(){
}
