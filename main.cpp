#include <iostream>
#include <cstdlib>
#include <ctime>
#include "header.hpp"

using namespace std;


int main (int argc, char* argv[]) {

    Type t;
	int x, i, L1, L2, L3, N, K;
    
    checkArguments(argc, argv, L1, L2, L3, N, K);
	Ballholder b(N,L1,L2,L3);
	
    
	for (i=0;i<K;i++) {		// K action (hits/rests)
        cout << endl << "Action " << i+1 << endl;	
    	x = b.hit_a_ball();	// Hit a random ball
        cout << "Rest any other ball" << endl;
		b.rest_the_others(x);	// Rest all balls apart from d	
	}
	/* Pick game to play */
	t = b.more_ok_balls();
	if (t == TENNIS) cout << "We will play tennis" << endl;
	else if (t == BASKETBALL) cout << "We will play basketball" << endl;
	else cout << "We will play pingpong" << endl << endl;

	return 0;
}
