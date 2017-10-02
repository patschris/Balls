#include <iostream>
#include <cstdlib>
#include "header.hpp"

using namespace std;


Tennis::Tennis(int L2):Ball(L2) {}


Tennis::~Tennis() {}


Type Tennis::get_type() {
	return TENNIS;
}


void Tennis::hit() {
	cout << "Trying to hit a Tennis' ball" << endl;	
	if (state == MISSING) { // Ball is out of the game because it is missing
		cout << "You cannot hit a hidden ball!" << endl;
	}
	else if (state == WORN) {	
		cout << "Plof!" << endl; // Plof because I hit a worn ball
	}
    else {
	    cout << "Tsaf!" << endl; // Tsaf because I hit a ball with ok status
	    durability-=5;
	    if (durability <= 0) state = WORN;
	    if (rand() % 10==7) state = MISSING;
    }
}

void Tennis::rest(){
	if (state!=MISSING && state!= BROKEN) {
		durability+=3;
		if (state == WORN && durability > 0) state = OK;
	}
}
