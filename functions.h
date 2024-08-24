#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "accessories.h"
#include "watercraft.h"
using namespace std;



int printMenu( );
void TAV( vector<watercraft *> inventory ); 
void printSpecs( vector<watercraft *> inventory ); 
void deleteWatercraft( vector<watercraft *> &inventory ); 
void searchByType( vector<watercraft *> inventory );
void searchByMotorType( vector<watercraft *> inventory );
void printByPrice( vector<watercraft *> inventory );
void printList( vector<watercraft *> inventory );

#endif /* FUNCTIONS_H */

