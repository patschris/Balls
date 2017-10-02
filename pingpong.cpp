#include <iostream>
#include <cstdlib>
#include "header.hpp"

using namespace std;


Pingpong::Pingpong(int L3):Ball(L3) {}


Pingpong::~Pingpong() {}


Type Pingpong::get_type() {
	return PINGPONG;
}


void Pingpong::hit() {
	int x;
	cout << "Trying to hit a Pingpong's ball" << endl;
	if (state == BROKEN) { // Ball is out of the game because it is broken
		cout << "The ball is broken" << endl;	
	}
	else if (state == MISSING) {	// Ball is out of the game because it is missing
		cout << "You cannot hit a hidden ball!" << endl;
		return;
	}
	else if (state == WORN) {	
		cout << "Plof!" << endl; // Plof because I hit a worn ball
	}
    else {
	    cout << "Tsaf!" << endl; // Tsaf because I hit a ball with ok status
	    durability--;
	    if (durability == 0) state = WORN;
	    x = rand() % 10;
	    if (x==6) state = MISSING;
	    if (x==9) state = BROKEN;
    }
}


void Pingpong::rest(){
	if (state != MISSING && state != BROKEN) {
		durability++;
		if (state == WORN) state = OK;
	}
}
