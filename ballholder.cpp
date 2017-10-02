#include <iostream>
#include <cstdlib>
#include <ctime>
#include "header.hpp"

using namespace std;


/* Constructs N balls of random type */
Ballholder::Ballholder (int N, int L1, int L2, int L3) {
	int x,i;
	n=N;
	array = new Ball*[n];
	basketball_ok = 0;
	tennis_ok = 0;
	pingpong_ok = 0;
	srand(time(NULL));
	for (i=0; i<n; i++){
        /* Construct N balls randomly */
		x= rand() % 3 + 1;
		if (x==1) {
			array[i] = new Basketball(L1);
			basketball_ok ++;
		}
		else if (x==2){
			 array[i] = new Tennis(L2);
			 tennis_ok ++;
		}
		else {
			 array[i] = new Pingpong(L3);
			 pingpong_ok ++;
		}
	}
	cout << endl << tennis_ok << " tennis' balls just constructed" << endl;
	cout << pingpong_ok << " pingpong's balls just constructed" << endl;
	cout << basketball_ok << " basketballs just constructed" << endl;
}


Ballholder::~Ballholder() {
	int i;	
	for (i=0; i<n; i++) delete array[i];	 
	delete[] array;
}


/* Hits a ball randomly regardless the type*/
int Ballholder::hit_a_ball() {
	int x = rand() % n;
	array[x]->hit();
	if (array[x]->get_type() == TENNIS && array[x]->get_state() != OK){
		if (tennis_ok > 0) tennis_ok -- ;
	}
	if (array[x]->get_type() == BASKETBALL && array[x]->get_state() != OK){
		if (basketball_ok > 0) basketball_ok -- ;
	}
	if (array[x]->get_type() == PINGPONG && array[x]->get_state() != OK){
		if (pingpong_ok > 0) pingpong_ok -- ;
	}
	return x;
}


/* Rests the balls apart from x */
void Ballholder::rest_the_others(int x) {
    int i;
	State previous;
	for (i=0; i<n; i++){
		if (i!=x) {
		    previous=array[i]->get_state(); // state before rest
		    array[i]->rest();	// call proper rest function
		    if (array[i]->get_state() == OK && previous == WORN) {
			    if (array[i]->get_type()==TENNIS) tennis_ok++; 
			    else if(array[i]->get_type()==BASKETBALL) basketball_ok++;
			    else pingpong_ok++;
		    }
        }
	}
}


/* Finds the type that has more ok balls remaining in the game */
Type Ballholder::more_ok_balls() {	
	int max = tennis_ok;
    Type t = TENNIS;
	if (pingpong_ok > max) {
        max = pingpong_ok;
        t = PINGPONG; 
    }
	if (basketball_ok > max) {
        max = basketball_ok;
        t = BASKETBALL; 
    }
	cout << endl <<"Remaining balls" << endl; 
	cout << "Tennis' balls: " << tennis_ok << endl;
	cout << "Pingpong's balls: " << pingpong_ok << endl;
	cout << "Basketballs: " << basketball_ok << endl;
    return t;
}
