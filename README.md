# Balls
The program needs exactly five integers as arguments. Specifically:
- *L<sub>1</sub>*: durability of Basketball's ball, 
- *L<sub>2</sub>*: durability of Tennis' ball
- *L<sub>3</sub>*: durability of Ping-pong's ball
- *N*: total amount of balls
- *K*: total amount of actions (hit/rest).

</br>Assumptions:
1. L<sub>1</sub> > L<sub>2</sub> > L<sub>3</sub>
2. a ball is worn when it's durability is less than or equal to zero 
3. we can't rest a Basketball's ball 
4. a ball can be hidden after a hit with probability 10%
5. a ping-pong's ball can be broken after a hit with probability 10%, if the ball isn't already hidden
6. can't hit a hidden ball
7. can't hit a broken ball (only in ping-pong case)
8. a ball is playable if and only if it's durability is greater than zero.  

</br>Contains makefile: `make` to compile and `make clean` to delete the object files and the executable.
</br>Written in C++, Ubuntu 16.04.3 LTS.
</br>__Keywords__: virtual, pure virtual, abstract class, inheritance, encapsulation, initializer list.
