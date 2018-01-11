#pragma once

#include "fstream"
#include "GEOKO.h"

using namespace std;

// Liest einen Double-Wert von einem ifstream
// @param zu lesende Datei, endesymbol
double readDoubleFile(ifstream *, char);

// Liest einen Integer-Wert von der Konsole
int readInt();

void writeListe(GEOKO *arr[], int anz, string name);