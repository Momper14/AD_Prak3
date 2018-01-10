#include "DVK.h"
#include "malloc.h"
#include "iostream"
#include "fstream"
#include "Util.h"

DVK::DVK(int anzahl, string name){
	this->anz = anzahl;

	GEOKO *tmp;
	ifstream datei(name);

	for(int i = 0; i < anzahl; i++){

		double br, la;

		br = readDoubleFile(&datei, ',');
		la = readDoubleFile(&datei, ';');

		tmp = dezToTime(br, la);

		this->index[i] = tmp;

		if(i == 0){
			this->anker_V = tmp;
		}
		if(i > 0 && i < anzahl){
			this->index[i - 1]->setN(tmp);
			tmp->setV(this->index[i - 1]);
		}
		if(i == anzahl - 1){
			this->anker_R = tmp;
		}
	}
	datei.close();

	if(this->middle != nullptr){
		delete this->middle;
	}
	middleNew();
}

void DVK::middleNew(){
	double brAvg = 0.0, laAvg = 0.0, brTmp, laTmp;

	for(int i = 0; i < this->anz; i++){
		timeToDez(index[i], &brTmp, &laTmp);
		brAvg += brTmp;
		laAvg += laTmp;
	}

	brAvg /= this->anz;
	laAvg /= this->anz;

	this->middle = dezToTime(brAvg, laAvg);
}

DVK::~DVK(){
}
