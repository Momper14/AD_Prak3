#include "DVKE.h"



DVKE::DVKE(DVKE * v, DVKE * n){
	this->n = n;
	this->v = v;
}

DVKE::DVKE() :DVKE(nullptr, nullptr){
}


DVKE * DVKE::getV() const{
	return this->v;
}

void DVKE::setV(DVKE *v){
	this->v = v;
}

DVKE * DVKE::getN() const{
	return this->n;
}

void DVKE::setN(DVKE *n){
	this->n = n;
}

DVKE::~DVKE(){
}
