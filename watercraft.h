#ifndef WATERCRAFT_H
#define WATERCRAFT_H

#include <fstream>
#include <vector>
#include <string>
#include "accessories.h"
using namespace std;


class watercraft {
	private:
		string type;      // [15] e.g. pontoon, sport boat, sailboat, fishing, 
	                    	//      canoe, kayak, jetski, etc.
		string make;      // [20]
		string model;     // [30]
		int propulsion;   // 0 = none; 1 = outBoard; 2 = inBoard; 
		string engine;    // [15] Suzuki, Yamaha, etc.
		int hp;			   // horse power	
		string color;     // [25]
		int length;       // feet
		double base_price;
		double total_price;
		accessories extras;
	
	public:
		watercraft();
	   	watercraft( string wType, string wMake, string wModel, 
						int wPropulsion, string wEngine, int wHP, 
						string wColor, int wLength, double wBPrice, 
						double wTPrice, double wBimini, double wTowbar,
						double wStereo, double wTable, double wGPS,
						double wAnchor, double wPaddles ) : type(wType), 
						make(wMake), model(wModel), propulsion(wPropulsion), 
						engine(wEngine), hp(wHP), color(wColor),
						length(wLength), base_price(wBPrice),
						total_price(wTPrice), extras(wBimini, wTowbar,
						wStereo, wTable, wGPS, wAnchor, wPaddles)  { ; }

		watercraft( ifstream &inFile );
		void printWatercraft ( int index );
		string getType( ) { return type; }
		double getTPrice( ) { return total_price; }
		int getPropulsion( ) { return propulsion; }
		accessories getExtras( ) { return extras; }
		double getBPrice( ) { return base_price; }
};



#endif /* WATERCRAFT_H */
