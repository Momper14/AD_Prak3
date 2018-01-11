#include "DVK.h"
#include "malloc.h"
#include "iostream"
#include "fstream"
#include "Util.h"

// Initialisierungskonstruktor
DVK::DVK(int anzahl, string name){
	this->anz = anzahl;

	// Aktuelles gelesenes Element
	GEOKO *tmp;
	// Einzulesende Datei
	ifstream datei(name);

	// Einlesen der Datenpaare
	for(int i = 0; i < anzahl; i++){

		//eingelesener Breiten- und Längengrad
		double br, la;

		br = readDoubleFile(&datei, ',');
		la = readDoubleFile(&datei, ';');

		tmp = dezToTime(br, la);

		// Eintragen in Array
		this->index[i] = tmp;

		// vorderen Anker setzen
		if(i == 0){
			this->anker_V = tmp;
		}
		// Eintrage als Nachvolger im vorgänger und vorgänger eintragen
		if(i > 0 && i < anzahl){
			this->index[i - 1]->setN(tmp);
			tmp->setV(this->index[i - 1]);
		}
		// hinteren Anker setzen
		if(i == anzahl - 1){
			this->anker_R = tmp;
		}
	}
	datei.close();

	// middle neu berechnen
	middleNew();
}


// Berechnet den Mittelwert neu
void DVK::middleNew(){
	// alten Mittelwert löschen, falls vorhanden
	if(this->middle != nullptr){
		delete this->middle;
	}

	// Breiten- und Längengrad durchschnitt, wert des Aktuellen paares
	double brAvg = 0.0, laAvg = 0.0, brTmp, laTmp;

	// Alle werte zusammen rechnen
	for(int i = 0; i < this->anz; i++){
		timeToDez(index[i], &brTmp, &laTmp);
		brAvg += brTmp;
		laAvg += laTmp;
	}

	// Durch anzahl Elemente teilen
	brAvg /= this->anz;
	laAvg /= this->anz;

	// middle neu setzen
	this->middle = dezToTime(brAvg, laAvg);
}


// Destrukort
DVK::~DVK(){
	delete middle;
	delete[] *index;
}
