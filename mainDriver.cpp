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
#include "functions.h"
#include "watercraft.h"
#include "accessories.h"


int main(int argc, char* argv[]) {
	int choice;
	bool exit { false };

	//Create vector inventory
	vector<watercraft *> inventory;

	//Opening the file
	ifstream inFile(argv[1]);
	if (!inFile) {
		cout << "File is NULL" << endl;
		exit = true;
	}

	//While it is not exiting the program
	while(exit == false) {
		choice = printMenu();
		switch (choice) {
			case 1:
			{
				//Loading watercraft from file
				while(!inFile.eof()) {
					watercraft* craft = new watercraft(inFile);
					if (craft->getType() != "") {
						inventory.push_back(craft);
					}
				}
				cout << "\nLoaded watercraft from file.\n\n";
			}
				break;
			case 2:
			{
				//Add to front
				inventory.insert(inventory.begin(), new watercraft());
			}
				break;
			case 3:
			{
				//Add to rear
				inventory.push_back(new watercraft());
			}
				break;
			case 4:
			{
				cout << "\nThere are " << inventory.size() << " watercraft in inventory.\n\n";
			}
				break;
			case 5:
			{
				//printList function
				printList(inventory);
				cout << "\n\n";
			}	
				break;
			case 6:
			{
				printSpecs(inventory);
				cout << endl;
			}
				break;
			case 7:
			{
				deleteWatercraft(inventory);
				cout << endl;
			}
				break;
			case 8:
			{
				searchByType(inventory);
				cout << endl;
			}
				break;
			case 9:
			{
				searchByMotorType(inventory);
				cout << endl;
			}
				break;
			case 10:
			{
				printByPrice(inventory);
				cout << "\n\n";
			}
				break;
			case 11:
			{
				cout << endl;
				TAV(inventory);
				cout << endl;
			}
				break;
			case 12:
				exit = true;
				break;
			default:
				//Check if there was invalid input
				cout << "\nInvalid input. Try again.\n\n";
				break;
			}
	}
	//Return statement
	return 0;
}
