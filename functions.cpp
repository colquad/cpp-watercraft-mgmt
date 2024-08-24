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

int printMenu( ) {
	//Prints the menu
	int choice;
	cout << "1. load inventory of watercraft from file\n";
	cout << "2. add additional watercraft to front of list\n";
	cout << "3. add additional watercraft to end of list\n";
	cout << "4. number of watercraft in inventory\n";
	cout << "5. print inventory of watercraft\n";
	cout << "6. print specs of chosen watercraft\n";
	cout << "7. delete chosen watercraft\n";
	cout << "8. search watercraft by type\n";
	cout << "9. search watercraft by motor type\n";
	cout << "10. sort watercraft by price\n";
	cout << "11. total asset value in inventory\n";
	cout << "12. quit program\n";
	cin >> choice;

	//Returns user input
	return choice;
}

void TAV ( vector <watercraft *> inventory ) {
	//Variable to store the total price
	long double priceTotal = 0.0;
	int size = inventory.size();
	
	//Range based loop to add up the total price
	for (auto i = 0; i < size; ++i) {
		priceTotal += inventory[i]->getTPrice();
	}
	cout << "Total asset value of all inventory is: " << fixed << setprecision(2) << priceTotal << "\n\n";
}

void printSpecs( vector<watercraft *> inventory ) {
	int num;

	//printList function
	printList(inventory);

	
	cout << "\nEnter the # of the watercraft for the specs:\n";
	cin >> num;
	num -= 1;

	inventory[num]->printWatercraft(num);
	cout << "\n";

	//If else to decide which type of motor it prints
	if (inventory[num]->getPropulsion() == 0) {
		cout << "\tno motor\n";
	}
	else if (inventory[num]->getPropulsion() == 1) {
		cout << "\tout-board\n";
	}
	else {
		cout << "\tin-board\n";
	}

	//printing the base price
	cout << "\tbase price: $" << setw(10) << left << fixed << setprecision(2) << right <<
		inventory[num]->getBPrice() << "\n";

	//Printing the extras if they have them
	if (inventory[num]->getExtras().get_bimini() != 0) {
		cout << setw(10) << left << "\tBimini: " << "$" << setw(10) << left << fixed <<
			setprecision(2) << right << inventory[num]->getExtras().get_bimini() << "\n";
	}
	if (inventory[num]->getExtras().get_towbar() != 0) {
		cout << setw(10) << left << "\tTowbar: " << "$" << setw(10) << left << fixed <<
			setprecision(2) << right << inventory[num]->getExtras().get_towbar() << "\n";
	}
	if (inventory[num]->getExtras().get_stereo() != 0) {
		cout << setw(10) << left << "\tStereo: " << "$" << setw(10) << left << fixed <<
			setprecision(2) << right << inventory[num]->getExtras().get_stereo() << "\n";
	}
	if (inventory[num]->getExtras().get_table() != 0) {
		cout << setw(10) << left << "\tTable: " << "$" << setw(10) << left << fixed <<
			setprecision(2) << right << inventory[num]->getExtras().get_table() << "\n";
	}
	if (inventory[num]->getExtras().get_gps() != 0) {
		cout << setw(10) << left << "\tGPS: " << "$" << setw(10) << left << fixed <<
			setprecision(2) << right << inventory[num]->getExtras().get_gps() << "\n";
	}
	if (inventory[num]->getExtras().get_anchor() != 0) {
		cout << setw(10) << left << "\tAnchor: " << "$" << setw(10) << left << fixed <<
			setprecision(2) << right << inventory[num]->getExtras().get_anchor() << "\n";
	}
	if (inventory[num]->getExtras().get_paddles() != 0) {
		cout << setw(10) << left << "\tPaddles: " << "$" << setw(10) << left << fixed <<
			setprecision(2) << right << inventory[num]->getExtras().get_paddles() << "\n";
	}
	cout << endl;
}

void deleteWatercraft( vector<watercraft *> &inventory ) {
	//printList function
	printList(inventory);

	int choice;
	cout << "Select a watercraft to delete: " << endl;
	cin >> choice;
	choice -= 1;

	//Deletes the node
	inventory.erase(inventory.begin() + choice);
}

void searchByType( vector<watercraft *> inventory ) {
	int choice;
	int size = inventory.size();

	cout << "Type of watercraft to search for: \n";
	cout << "1. Pontoon" << endl;
	cout << "2. Fishing" << endl;
	cout << "3. Sport boat" << endl;
	cout << "4. Kayak" << endl;
	cout << "5. Canoe" << endl;
	cout << "6. Sailboat" << endl;
	cin >> choice;

	//Finds which watercrafts are of this type and prints them
	switch (choice) {
		case 1:
			for (auto i = 0; i < size; ++i) {
				if (inventory[i]->getType() == "pontoon") {
					inventory[i]->printWatercraft(i);
				}
			}
			break;
		case 2:
			for (auto i = 0; i < size; ++i) {
				if (inventory[i]->getType() == "fishing") {
					inventory[i]->printWatercraft(i);
				}
			}
			break;
		case 3:
			for (auto i = 0; i < size; ++i) {
                                if (inventory[i]->getType() == "sport boat") {
                                        inventory[i]->printWatercraft(i);
                                }
                        }
                        break;
		case 4:
			for (auto i = 0; i < size; ++i) {
                                if (inventory[i]->getType() == "kayak") {
                                        inventory[i]->printWatercraft(i);
                                }
                        }
                        break;
		case 5:
			for (auto i = 0; i < size; ++i) {
                                if (inventory[i]->getType() == "canoe") {
                                        inventory[i]->printWatercraft(i);
                                }
                        }
                        break;
		case 6:
			for (auto i = 0; i < size; ++i) {
                                if (inventory[i]->getType() == "sailboat") {
                                        inventory[i]->printWatercraft(i);
                                }
                        }
                        break;
		default:
			cout << "\nNot a valid choice\n\n";
			break;
	}
			
}

void searchByMotorType( vector<watercraft *> inventory ) {
	int choice;
	int size = inventory.size();

	cout << "Type of motor to search for:\n\t";
	cout << "1. no motor\n";
	cout << "2. out-board\n";
	cout << "3. in-board\n";
	cin >> choice;
	choice -= 1;

	//Finds which watercrafts have this motor type and prints them
	switch (choice) {
		case 1:
			for (auto i = 0; i < size; ++i) {
				if (inventory[i]->getPropulsion() == 0) {
					inventory[i]->printWatercraft(i);
				}
			}
			break;
		case 2:
			for (auto i = 0; i < size; ++i) {
				if (inventory[i]->getPropulsion() == 1) {
					inventory[i]->printWatercraft(i);
				}
			}
			break;
		case 3:
			for (auto i = 0; i < size; ++i) {
				if (inventory[i]->getPropulsion() == 2) {
					inventory[i]->printWatercraft(i);
				}
			}
			break;
		default:
			cout << "\nNot a valid choice\n\n";
			break;
	}
}

//Helper function to sort
bool sortHelp(watercraft* a, watercraft* b) {
        return a->getTPrice() < b->getTPrice();
}

void printByPrice( vector<watercraft *> inventory ) {
	//Create temporary vector to change the list without affecting the actual list
	vector<watercraft *> temp = inventory;

	//Sort function using helper function
	sort(temp.begin(), temp.end(), sortHelp);

	int size = inventory.size();
	for(auto i = 0; i < size; ++i) {
		temp[i]->printWatercraft(i);
	}
}

//Function to print entire list
void printList( vector<watercraft *> inventory ) {
	int size = inventory.size();

	//Loops through vector and prints the watercraft every time
	for (auto i = 0; i < size; ++i) {
		inventory[i]->printWatercraft(i);
	}
}
