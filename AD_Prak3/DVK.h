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
	DVK(long, string);


	// Getter
	GEOKO * getMiddle() const;


	// Berechnet den Mittelwert neu
	void middleNew();

	// Implementierung des Bubble-Sort-Algorythmus
	void bubbleSort();

	// Implementierung des Insertion-Sort-Algorythmus
	void insertionSort();

	// Implementierung des Quick-Sort-Algorythmus
	void quicksort();

	// Teilt den Array auf und sortiert nach Pivot
	void split(int, int, GEOKO *[]);

	// Verschiebt das rechte Element hinter das linke
	void change(int, int, GEOKO *[]);

	// Implementierung des Selection-Sort-Algorythmus
	void selectionSort();

	void mergeSort();

	void mergeSortAlg(int, int, GEOKO*[]);


	void merge(int, int, int, GEOKO*[]);

	// Destrukort
	~DVK();
};

