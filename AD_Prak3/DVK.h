#pragma once
#define MAXELE 1000000

#include "GEOKO.h"
#include "string"

using namespace std;

class DVK{
private:
	// Anker der Liste, Mittelwert aller einträge, Liste mit allen Elementen
	GEOKO * anker_V, *anker_R, *middle, *index[MAXELE];
	// Anzahl der Elemente in der Liste
	int anz;
public:
	// Initialisierungskonstruktor
	DVK(int, string);

	// Berechnet den Mittelwert neu
	void middleNew();

	// Destrukort
	~DVK();
};

