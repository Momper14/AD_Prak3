#include "iostream"
#include "DVK.h"
#include "string"
#include "Util.h"
#include "windows.h"

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
						name = datei1;
						break;
					case 2:
						name = datei2;
						break;
				}

				cout << "Anzahl der Kooridinatenpaare ? (max " << MAXELE << "):" << endl;
				do{
					anz = readInt();
				} while(anz > MAXELE || anz < 1);

				liste = new DVK(anz, name);

				double br, la;

				timeToDez(liste->getMiddle(), &br, &la);
				cout << "Breitengrad: " << br << ", Laengengrad: " << la << endl;
			}
			break;

			case 2:
			{
				//----------------------------------------------------------------------
				//
				//    Zeitmessung im æs-Bereich
				//    TESTANWENDUNG
				//    Author: tbird
				//    Date: 20.11.2007
				//
				//----------------------------------------------------------------------

				// Variablen
				LONGLONG g_Frequency, g_FirstNullCount, g_LastNullCount, g_FirstCount, g_LastCount;

				// Frequenz holen
				if(!QueryPerformanceFrequency((LARGE_INTEGER*) &g_Frequency))
					printf("Performance Counter nicht vorhanden");

				double resolution = 1000000 / ((double) g_Frequency);

				printf("Frequenz des Counters:  %lld kHz\n", g_Frequency / 1000);  //lld -> LONGLONG darstellung
				printf("Dadurch maximale Aufloesung: %4.5f us\n", resolution);

				// null-messung
				QueryPerformanceCounter((LARGE_INTEGER*) &g_FirstNullCount);
				QueryPerformanceCounter((LARGE_INTEGER*) &g_LastNullCount);
				double nulltime = (((double) (g_LastNullCount - g_FirstNullCount)) / ((double) g_Frequency));

				printf("Null-Zeit: %4.5f us\n", nulltime * 1000000);

				// beginn messung
				QueryPerformanceCounter((LARGE_INTEGER*) &g_FirstCount);

				// ###############
				// # Bubble Sort #
				// ###############
				liste->bubbleSort();

				// 2. Messung
				QueryPerformanceCounter((LARGE_INTEGER*) &g_LastCount);

				double dTimeDiff = (((double) (g_LastCount - g_FirstCount)) / ((double) g_Frequency));

				// Von der gemessenen Zeit die "Null-Zeit" abziehen, um genauer zu werden
				double time = (dTimeDiff - nulltime) * 1000000; //mikro-sekunden
				printf("Zeit: %4.5f us\n", time);
			}
			break;
			case 3:
			{
				//----------------------------------------------------------------------
				//
				//    Zeitmessung im æs-Bereich
				//    TESTANWENDUNG
				//    Author: tbird
				//    Date: 20.11.2007
				//
				//----------------------------------------------------------------------

				// Variablen
				LONGLONG g_Frequency, g_FirstNullCount, g_LastNullCount, g_FirstCount, g_LastCount;

				// Frequenz holen
				if(!QueryPerformanceFrequency((LARGE_INTEGER*) &g_Frequency))
					printf("Performance Counter nicht vorhanden");

				double resolution = 1000000 / ((double) g_Frequency);

				printf("Frequenz des Counters:  %lld kHz\n", g_Frequency / 1000);  //lld -> LONGLONG darstellung
				printf("Dadurch maximale Aufloesung: %4.5f us\n", resolution);

				// null-messung
				QueryPerformanceCounter((LARGE_INTEGER*) &g_FirstNullCount);
				QueryPerformanceCounter((LARGE_INTEGER*) &g_LastNullCount);
				double nulltime = (((double) (g_LastNullCount - g_FirstNullCount)) / ((double) g_Frequency));

				printf("Null-Zeit: %4.5f us\n", nulltime * 1000000);

				// beginn messung
				QueryPerformanceCounter((LARGE_INTEGER*) &g_FirstCount);

				// ##################
				// # Insertion Sort #
				// ##################
				//liste->insertionSort();

				// 2. Messung
				QueryPerformanceCounter((LARGE_INTEGER*) &g_LastCount);

				double dTimeDiff = (((double) (g_LastCount - g_FirstCount)) / ((double) g_Frequency));

				// Von der gemessenen Zeit die "Null-Zeit" abziehen, um genauer zu werden
				double time = (dTimeDiff - nulltime) * 1000000; //mikro-sekunden
				printf("Zeit: %4.5f us\n", time);
			}
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