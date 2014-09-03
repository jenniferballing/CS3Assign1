#include <iostream>
#include "Board.h"
#include "Queue.h"

using namespace std;

/*Jennifer Balling
A00890700
CS 3, Assignment 1: Solve the number cubes*/


int main(){

	//Board creation and manipulation Test: 
	//working
	Board inputOne;// , inputTwo, inputThree, inputFourRandom;
	inputOne.board[0][0] = 1;
	inputOne.board[0][1] = 2;
	inputOne.board[0][2] = 3;
	inputOne.board[1][0] = 6;
	inputOne.board[1][1] = 5;
	inputOne.board[1][2] = 4;
	inputOne.board[2][0] = 9;
	inputOne.board[2][1] = 7;
	inputOne.board[2][2] = 8;
	
	cout<< inputOne.toString();

	//Queue creation and manipulation Test:
	//Working
	Queue testQueue;
	

	//Game Logic
	//Insert initial state into queue.
	testQueue.Insert(inputOne);

	//Now delete this state and insert the 12 substates
	testQueue.Delete(inputOne);
	
	Board east(inputOne);
	east.rotateEast(0);
	testQueue.Insert(east);
	Board west(inputOne);
	west.rotateWest(0);
	testQueue.Insert(west);
	Board north(inputOne);
	north.rotateNorth(0);
	testQueue.Insert(north);
	Board south(inputOne);
	south.rotateSouth(0);
	testQueue.Insert(south);

	
	

	return 0;
}
