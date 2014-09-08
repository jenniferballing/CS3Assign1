#include <iostream>
#include "Board.h"
#include "Queue.h"
#include "BoardObject.h"

using namespace std;

/*Jennifer Balling
A00890700
CS 3, Assignment 1: Solve the number cubes*/

//Functions that return the appropriate starting boards
Board inputBoardOne();
Board inputBoardTwo();
Board inputBoardThree();
Board inputRandomBoard();
void rotateBoard(Queue);
void gameLogic(Queue);

int main(){

	
	Board inputOne;
	inputOne = inputBoardOne();
	Queue myQueue;
	
	myQueue.Insert(inputOne);
	rotateBoard(myQueue);
	//gameLogic(myQueue);
	
	

	//Queue creation and manipulation Test:
	//Working
	Queue testQueue;
	

	
	return 0;
}
Board inputBoardOne()
{
	Board b;
	
	//One dimentional array with the values in the initial order
	int arr[9] = { 1, 2, 3, 6, 4, 5, 9, 7, 8 };	
	int num = 0;
	
	//Two dimentional array to set initial values in board
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			b.board[i][j] = arr[num];
			num++;
		}
	}
	return b;
}

Board inputBoardTwo()
{
	Board b;

	//One dimentional array with the values in the initial order
	int arr[9] = { 1, 8, 3, 5, 2, 4, 7, 6, 9 };
	int num = 0;

	//Two dimentional array to set initial values in board
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			b.board[i][j] = arr[num];
			num++;
		}
	}
	return b;
}

Board inputBoardThree()
{
	Board b;

	//One dimentional array with the values in the initial order
	int arr[9] = { 6, 7, 2, 1, 5, 9, 3, 4, 8 };
	int num = 0;

	//Two dimentional array to set initial values in board
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			b.board[i][j] = arr[num];
			num++;
		}
	}
	return b;
}

void rotateBoard(Queue myQueue)
{
	//Goal board
	Board winningBoard;
	int count = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			winningBoard.board[i][j] = count;
			count++;
		}
	}

	int currentState = 0;
	string prevLocation = 0;
	
	bool win = false;
	while (!win)
	{
		BoardObject obj;
		//get first obj
		obj = myQueue.head->boardObj;
		//delete it from queue
		myQueue.Delete();
		//get the prev location
		prevLocation = obj.getLocation();

		obj.setSequence = currentState;
		
		
		currentState++;
		
		
	}

	



	
	int seqCounter = 0;
	while (!win)
	{
		Board b = myQueue.head->gameBoard;
		myQueue.Delete();
		BoardObject obj;
		Board n0(b), s0(b), e0(b), w0(b), n1(b), s1(b), e1(b), w1(b), n2(b), s2(b), e2(b), w2(b);

		Board nArr[3] = { n0, n1, n2 };
		Board sArr[3] = { s0, s1, s2 };
		Board eArr[3] = { e0, e1, e2 };
		Board wArr[3] = { w0, w1, w2 };
		int num = 0;
		for (int i = 0; i < 3; i++)
		{
			nArr[i].rotateNorth(i);
			myQueue.Insert(nArr[i]);
			obj.setBoard(nArr[i]);
			obj.setDir("North");
			obj.setRowCol("Col" + to_string(i));
			obj.setTier()
			obj.setSequence(seqCounter);
			obj.printObj();
			//cout << nArr[i].toString() << endl;
			seqCounter++;

			sArr[i].rotateSouth(i);
			myQueue.Insert(sArr[i]);
			obj.setBoard(nArr[i]);
			obj.setDir("South");
			obj.setRowCol("Col" + to_string(i));
			obj.setSequence(seqCounter);
			obj.printObj();
			//cout << sArr[i].toString() << endl;
			seqCounter++;

			eArr[i].rotateEast(i);
			myQueue.Insert(eArr[i]);
			obj.setBoard(nArr[i]);
			obj.setDir("East");
			obj.setRowCol("Row" + to_string(i));
			obj.setSequence(seqCounter);
			obj.printObj();
			//cout << eArr[i].toString() << endl;
			seqCounter++;

			wArr[i].rotateWest(i);
			myQueue.Insert(wArr[i]);
			obj.setBoard(nArr[i]);
			obj.setDir("West");
			obj.setRowCol("Row" + to_string(i));
			obj.setSequence(seqCounter);
			obj.printObj();
			//cout << wArr[i].toString() << endl;
			seqCounter++;

		}
		if (myQueue.head->gameBoard == winningBoard)
		{

			cout << myQueue.head->gameBoard.toString() << endl;
			cout << "You win! YAY!" << endl;
			win = true;
		}
	}	
}

void gameLogic(Queue myQueue)
{
	
}
