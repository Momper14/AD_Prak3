#include "Util.h"
#include "string"
#include "iostream"
#include "algorithm"

// Liest einen Double-Wert von einem ifstream
// @param zu lesende Datei, endesymbol
double readDoubleFile(ifstream *ifs, char det){
	string tmp;

	getline(*ifs, tmp, det);
	// L�schen der leerzeichen
	tmp.erase(remove_if(tmp.begin(), tmp.end(), isspace), tmp.end());

	return stod(tmp);
}

// Liest einen Integer-Wert von der Konsole
int readInt(){
	string tmp;
	int bed = 1;
	int ret = NULL;

	do{
		cin >> tmp;
		try{
			ret = stoi(tmp);
			bed = 0;
		} catch(const invalid_argument& e){
			cout << "Kein gueltiger Integer-Wert" << endl;
		}
	} while(bed);

	return ret;
}
