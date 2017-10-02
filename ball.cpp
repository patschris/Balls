#include "header.hpp"

using namespace std;


Ball::Ball(int L) {
	durability = L;
	state = OK;
}
	
Ball::~Ball() {}

void Ball::hit() {} 


void Ball::rest() {}


State Ball::get_state(){
	return state;
}
