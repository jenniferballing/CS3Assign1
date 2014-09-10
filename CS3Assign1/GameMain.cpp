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
void gameLogic(Queue);
BoardObject* returnBoards(Queue, Board);

int main(){

	BoardObject obj;
	Board inputOne;
	inputOne = inputBoardOne();
	obj.setBoard(inputOne);
	
	Queue myQueue;
	myQueue.Insert(obj);
	gameLogic(myQueue);
	
	return 0;
}

BoardObject* returnBoards(Queue myQueue, Board b)
{
	Board temp;
	temp = b;
	BoardObject arr [12];
	int num = 0;

	for (int i = 0; i < 3; i++)
	{
		temp.rotateNorth(i);
		arr[num].setBoard(temp);
		arr[num].setLocation("North Col " + to_string(i));
		temp = b;
		num++;

		temp.rotateSouth(i);
		arr[num].setBoard(temp);
		arr[num].setLocation("South Col" + to_string(i));
		temp = b;
		num++;

		temp.rotateEast(i);
		arr[num].setBoard(temp);
		arr[num].setLocation("East Row" + to_string(i));
		temp = b;
		num++;

		temp.rotateWest(i);
		arr[num].setBoard(temp);
		arr[num].setLocation("West Row" + to_string(i));
		temp = b;
		num++;
	}
	return arr;
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

void gameLogic(Queue myQueue)
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
	int prevState = 0;
	int num = 0;
	
	bool win = false;
	int prev = 0;
	while (!win)
	{
		//get first obj
		BoardObject parentObj;		
		parentObj = myQueue.head->boardObj;
		Board parentBoard = parentObj.getBoard();

		if (parentBoard == winningBoard)
		{
			Board board = myQueue.head->boardObj.getBoard();

			cout << board.toString() << endl;
			cout << "You win! YAY!" << endl;
			win = true;
			return;
		}
		
		//delete it from queue
		myQueue.Delete();
		
		//Get the rotations
		BoardObject *boardObjArr = returnBoards(myQueue, parentBoard);

		
		

		
		for (int i = 0; i < 12; i++)
		{
			Board *childBoard = &boardObjArr[i].getBoard();
			
			
			BoardObject childObj;
			childObj.setBoard(*childBoard);

			//childObj.setBoard(childBoard);
			childObj.setTier(prev);
			childObj.setSequence(currentState);
			
			string prevLocation = parentObj.getLocation();
			string *currentMove = &boardObjArr[i].getLocation(); 			
			childObj.setLocation(*currentMove + " " + prevLocation);
			childObj.printObj();
			
			currentState++;
		}prev++;
	}
}


