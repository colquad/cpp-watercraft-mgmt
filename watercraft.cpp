/*
 * Colin Quade
 * CPSC 1020
 * cquade@clemson.edu
 * Professor Kittelstad
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include "watercraft.h"

using namespace std;

	watercraft::watercraft() {
		string field;

		cin.ignore();
		cout << "Enter type: ";
		getline(cin, type);

		cout << "Enter make: ";
		getline(cin, make);
		
		cout << "Enter model: ";
		getline(cin, model);
		
		cout << "Enter engine type: ";
		getline(cin, field);
		propulsion = stoi(field);
		
		cout << "Enter engine make: ";
		getline(cin, engine);
		
		cout << "Enter horsepower: ";
		getline(cin, field);
		hp = stoi(field);
		
		cout << "Enter color: ";
		getline(cin, color);
		
		cout << "Enter length: ";
		getline(cin, field);
		length = stoi(field);
		
		cout << "Enter base price: ";
		getline(cin, field);
		base_price = stod(field);
		
		cout << "Cost of bimini: ";
		getline(cin, field);
                extras.set_bimini(stod(field));
                
		cout << "Cost of towbar: ";
		getline(cin, field);
                extras.set_towbar(stod(field));
                
		cout << "Cost of stereo: ";
		getline(cin, field);
                extras.set_stereo(stod(field));
                
		cout << "Cost of table: ";
		getline(cin, field);
                extras.set_table(stod(field));
                
		cout << "Cost of gps: ";
		getline(cin, field);
                extras.set_gps(stod(field));
                
		cout << "Cost of anchor: ";
		getline(cin, field);
                extras.set_anchor(stod(field));
                
		cout << "Cost of paddles: ";
		getline(cin, field);
                extras.set_paddles(stod(field));

		total_price = base_price + extras.get_bimini() + extras.get_towbar() +
			extras.get_stereo() + extras.get_table() + extras.get_gps() +
			extras.get_anchor() + extras.get_paddles();
	}

	watercraft::watercraft( ifstream &inFile ) {
		string field;
		size_t pos;

		getline(inFile, type, ',');

		if (type != "") {
			getline(inFile, make, ',');

			getline(inFile, model, ',');
			
			getline(inFile, field, ',');
			propulsion = stoi(field, &pos);
			
			getline(inFile, engine, ',');
			
			getline(inFile, field, ',');
			hp = stoi(field, &pos);
			
			getline(inFile, color, ',');
			
			getline(inFile, field, ',');
			length = stoi(field, &pos);
			
			getline(inFile, field, ',');
			base_price = stod(field, &pos);
			
			getline(inFile, field, ',');
			total_price = stod(field, &pos);
			
			getline(inFile, field, ',');
			extras.set_bimini(stod(field, &pos));
			
			getline(inFile, field, ',');
			extras.set_towbar(stod(field, &pos));
			
			getline(inFile, field, ',');
			extras.set_stereo(stod(field, &pos));
			
			getline(inFile, field, ',');
			extras.set_table(stod(field, &pos));
			
			getline(inFile, field, ',');
			extras.set_gps(stod(field, &pos));
			
			getline(inFile, field, ',');
			extras.set_anchor(stod(field, &pos));
			
			getline(inFile, field, '\n');
			extras.set_paddles(stod(field, &pos));
		}
	}

	void watercraft::printWatercraft ( int index ) {
		printf("\n");
		cout << setw(2) << right << index + 1 << ". "
			<< setw(13) << left << type << setw(20) << left << make
			<< setw(23) << left << model << setw(11) << left << engine
			<< setw(5) << left << hp << setw(19) << left << color
			<< setw(5) << left << length << setw(10) << left << fixed
			<< setprecision(2) << right << total_price;
	}

