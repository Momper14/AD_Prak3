#include "DVK.h"
#include "malloc.h"


DVK::DVK(int anzahl, char name[]){
	this->anz = anzahl;
	*this->index = (GEOKO *) malloc(sizeof(GEOKO*) * MAXELE);

	GEOKO *tmp;

	for(int i = 0; i < anzahl; i++){

		// @todo lesen csv
		tmp = new GEOKO(1, 1, 1, 1, 1, 1);

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

	int brGrAvg = 0, laGrAvg = 0, brMinAvg = 0, laMinAvg = 0;
	double brSecAvg = 0.0, laSecAvg = 0.0;
	GEOKO * tmp;

	for(int i = 0; i < this->anz; i++){
		tmp = index[i];

		brGrAvg += tmp->getBrGr();
		laGrAvg += tmp->getLaGr();
		brSecAvg += tmp->getBrMin() * 60 + tmp->getBrSec();
		laSecAvg += tmp->getLaMin() * 60 + tmp->getLaSec();
	}

	brGrAvg /= this->anz;
	laGrAvg /= this->anz;
	brSecAvg /= this->anz;
	laSecAvg /= this->anz;
	brMinAvg = (int) (brSecAvg / 60);
	laMinAvg = (int) (laSecAvg / 60);
	brSecAvg -= brMinAvg * 60;
	laSecAvg -= laMinAvg * 60;

	this->middle = new GEOKO(brGrAvg, laGrAvg, brMinAvg, laMinAvg, brSecAvg, laSecAvg);
}

DVK::~DVK(){
}
