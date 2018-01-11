#pragma once
#define MAXELE 1000000
#define datei1 "Daten.csv"
#define datei2 "Daten1.csv"

#include "GEOKO.h"
#include "string"

using namespace std;

class DVK{
private:
	// Anker der Liste, Mittelwert aller einträge, Liste mit allen Elementen
	GEOKO * anker_V, *anker_R, *middle, *index[MAXELE];
	// Anzahl der Elemente in der Liste
	int anz;
	// Name der Datei
	string nameDat;
public:
	// Initialisierungskonstruktor
	DVK(int, string);

	// Berechnet den Mittelwert neu
	void middleNew();

	GEOKO * getMiddle() const;

	void bubbleSort();

	// Destrukort
	~DVK();
};

