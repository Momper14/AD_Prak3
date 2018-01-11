#include "iostream"
#include "cstring"
#include "DVK.h"
#include "string"
#include "Util.h"

using namespace std;

int main(){
	int choise = 0;
	DVK *liste = nullptr;

	do{
		cout << "1 Verkettete Liste anlegen" << endl
			<< "2 Bubble Sort" << endl
			<< "3 ???" << endl
			<< "4 Ende" << endl;

		choise = readInt();

		switch(choise){
			case 1:
			{
				if(liste != nullptr){
					delete liste;
				}

				string name;
				int anz;

				do{
					cout << "1 Daten.csv" << endl
						<< "2 Daten1.csv" << endl;

					choise = readInt();
				} while(!(choise == 1 || choise == 2));

				switch(choise){
					case 1:
						name = "Daten.csv";
						break;
					case 2:
						name = "Daten1.csv";
						break;
				}

				cout << "Anzahl der Kooridinatenpaare ? (max " << MAXELE << "):" << endl;
				do{
					anz = readInt();
				} while(anz > MAXELE || anz < 1);

				liste = new DVK(anz, name);
			}
			break;

			case 2:
				break;
			case 3:
				break;
			case 4:
				cout << "Auf wiedersehen" << endl;
				break;
			default:
				cout << "ungueltige eingabe!" << endl;
				break;
		}
	} while(choise != 4);

	if(liste != nullptr){
		delete liste;
	}
}