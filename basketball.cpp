#include <iostream>
#include <cstdlib>
#include "header.hpp"

using namespace std;


Basketball::Basketball(int L1): Ball(L1){}


Basketball::~Basketball(){}


Type Basketball::get_type() {
	return BASKETBALL;
}


void Basketball::hit(){
	int x;
	cout << "Trying to hit a Basketball" << endl;
	if (state == MISSING) { // Ball is out of the game because it is missing
		cout << "You cannot hit a hidden ball!" << endl;
	}
	else if (state == WORN) {
		cout << "Plof!" << endl; // Plof because I hit a worn ball
	}
    else {
	    cout << "Tsaf!" << endl; // Tsaf because I hit a ball with ok status
	    durability--;
	    if (durability == 0) state = WORN;
	    x = rand() % 10;
	    if (x==8) state = MISSING;
    }
}


void Basketball::rest(){}
