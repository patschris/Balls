#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include "header.hpp"

using namespace std;


/* Check if the given arguments are proper for the program */
void checkArguments (int argc, char *argv[], int& L1, int& L2, int& L3, int& N, int& K) {
    int i;    
    if (argc != 6) {
		cout << "You should give exactly 5 arguments!" << endl;
        cout << "L1: Durability of Basketball's ball" << endl;
        cout << "L2: Durability of Tennis' ball" << endl;
        cout << "L3: Durability of Ping-pong's ball" << endl;
        cout << "N: Total amount of balls" << endl;
        cout << "K: Total amount of actions" << endl;
		exit(-1);
	}
    for (i=1; i<argc; i++) {
        if (!validate(argv[i])) {
            cout << "Argumens should be integers" << endl;
            exit(-1);            
        }
    }
	L1 = atoi(argv[1]);
	L2 = atoi(argv[2]);
	L3 = atoi(argv[3]);
	N = atoi(argv[4]);
	K = atoi(argv[5]);
	if  ((L1 <= L2 && L2 <= L3) || (L1 <= L3)) {
		cout << "A basket ball should be stronger than a tennis ball, and a tennis ball should be stronger than a ping-pong ball!  (L1 > L2 > L3)" << endl;
		exit(-1);
	}
	if (L1 <= L2) {
		cout << "A basket ball should be stronger than a tennis ball!  (L1 > L2)" << endl;
		exit(-1);
	}
	if (L2 <= L3) {
		cout << "A tennis ball should be stronger than a ping pong-ball!  (L2 > L3)" << endl ;
		exit(-1);
	}
}


/* Check if a string contains only digits (0-9) */
bool validate (char *a) {
    unsigned int i;
    for (i=0; i<strlen (a); i++) {
        if (!isdigit (a[i])) { 
            return false;
        }
    }
    return true;
}
