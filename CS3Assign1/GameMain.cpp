#include <iostream>
#include "Board.h"
#include "Queue.h"

using namespace std;

/*Jennifer Balling
A00890700
CS 3, Assignment 1: Solve the number cubes*/

//Functions that return the appropriate starting boards
Board inputBoardOne();
Board inputBoardTwo();
Board inputBoardThree();
Board inputRandomBoard();
void rotateBoard(Board, Queue);
void gameLogic(Queue);

int main(){

	
	Board inputOne;
	inputOne = inputBoardOne();
	Queue myQueue;
	
	myQueue.Insert(inputOne);
	rotateBoard(inputOne, myQueue);
	gameLogic(myQueue);
	
	

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

void rotateBoard(Board b, Queue myQueue)
{
	//Create temp board
	Board temp = b;
	
	Board north0(temp), south0(temp), east0(temp), west0(temp), north1(temp), south1(temp), east1(temp), west1(temp), north2(temp), south2(temp), east2(temp), west2(temp);

	Board northArr[3] = { north0, north1, north2 };
	Board southArr[3] = { south0, south1, south2 };
	Board eastArr[3] = { east0, east1, east2 };
	Board westArr[3] = { west0, west1, west2 };
	int num = 0;
	for (int i = 0; i < 3; i++)
	{
		northArr[i].rotateNorth(i);
		myQueue.Insert(northArr[i]);
		cout << num << endl;
		cout << northArr[i].toString() << endl;
		num++;
	}
	for (int i = 0; i < 3; i++)
	{
		southArr[i].rotateSouth(i);
		myQueue.Insert(southArr[i]);
		cout << num << endl;
		cout << southArr[i].toString() << endl;
		num++;
	}
	for (int i = 0; i < 3; i++)
	{
		eastArr[i].rotateEast(i);
		myQueue.Insert(eastArr[i]);
		cout << num << endl;
		cout << eastArr[i].toString() << endl;
		num++;
	}
	for (int i = 0; i < 3; i++)
	{
		westArr[i].rotateWest(i);
		myQueue.Insert(westArr[i]);
		cout << num << endl;
		cout << westArr[i].toString() << endl;
		num++;
	}
	//Remove initial board
	//myQueue.Delete();
}

void gameLogic(Queue myQueue)
{
	//delete first node
	//myQueue.Delete();

	//Goal
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
	bool win = false;

	//get next and split to twelve more
	while(!win)
	{
		myQueue.Delete();
		Board b = myQueue.head->gameBoard;
		rotateBoard(b, myQueue);
		if (myQueue.head->gameBoard == winningBoard)
		{
			
			cout<< myQueue.head->gameBoard.toString()<<endl;
			cout << "You win! YAY!" << endl;
			win = true;
		}
	}
}
