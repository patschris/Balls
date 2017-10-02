#ifndef __header__
#define __header__


enum State {OK=0, WORN, MISSING, BROKEN};
/*      OK: Initial state
        WORN: durability==0
        MISSING: after a hit, with probability 10%, the ball will be hidden 
        BROKEN: only a ping-pong's ball can brake       */

enum Type {TENNIS=0, BASKETBALL, PINGPONG};	// Ball's type

class Ball {
	protected:	
		int durability;
		State state; 
	public:
		Ball(int);
		virtual ~Ball();
		virtual void hit();
		virtual void rest();
		virtual Type get_type()=0;
		State get_state();
};


class Tennis: public Ball {
	public:
		Tennis(int);
		~Tennis();
		void hit();
		void rest();
		Type get_type();
};


class Basketball: public Ball {
	public:
		Basketball(int);
		~Basketball();
		void hit();
		void rest();
		Type get_type();
};


class Pingpong: public Ball {
	public:
		Pingpong(int);
		~Pingpong();
		void hit();
		void rest();
		Type get_type();
};


/* Handles all balls of every type */
class Ballholder {
	private:
		Ball** array;
		int n, tennis_ok, basketball_ok, pingpong_ok;
	public:
		Ballholder(int,int,int,int);
		~Ballholder();
		int hit_a_ball();
		void rest_the_others(int);
		Type more_ok_balls();
};


void checkArguments (int, char **, int&, int&, int&, int&, int&);
bool validate (char *);

#endif
