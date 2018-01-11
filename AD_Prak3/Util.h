#pragma once

#include "fstream"

using namespace std;

// Liest einen Double-Wert von einem ifstream
// @param zu lesende Datei, endesymbol
double readDoubleFile(ifstream *, char);

// Liest einen Integer-Wert von der Konsole
int readInt();