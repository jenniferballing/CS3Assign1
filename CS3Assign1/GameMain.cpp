#include <iostream>
#include "Board.h"
#include "Queue.h"
#include "BoardObject.h"

using namespace std;

/*Jennifer Balling
A00890700
CS 3, Assignment 1: Solve the number cubes*/

Board inputBoards(int boardNumber);     //Initialize the correct board
void gameLogic(Queue, BoardObject);     //Run the game
BoardObject* returnBoards(Queue, Board);//Create the 12 new instances of the board and return them

int main(){

	//Create an instance of a BoardObject
	BoardObject obj;
	
	//Create instances of Boards
	Board boardInput;

	//Set the values in the Board
	//There are 4 input boards given in the assignment
	//The input board number is the argument 1, 2, 3 or 4(for a random board)
	boardInput = inputBoards(1);
	obj.setBoard(boardInput);
	
	//Create an instance of the queue
	Queue myQueue;

	//Insert the new object
	myQueue.Insert(obj);

	//Run the logic with the given object
	gameLogic(myQueue, obj);
	
	return 0;
}

Board inputBoards(int boardNumber)
{
	int arr[9];
	if (boardNumber == 1)
	{		
		arr[0] = 1;
		arr[1] = 2;
		arr[2] = 3;
		arr[3] = 6;
		arr[4] = 4;
		arr[5] = 5;
		arr[6] = 9;
		arr[7] = 7;
		arr[8] = 8;

	}
	else if (boardNumber == 2)
	{
		arr[0] = 1;
		arr[1] = 8;
		arr[2] = 3;
		arr[3] = 5;
		arr[4] = 2;
		arr[5] = 4;
		arr[6] = 7;
		arr[7] = 6;
		arr[8] = 9;
	}
	else if (boardNumber == 3)
	{
		arr[0] = 6;
		arr[1] = 7;
		arr[2] = 2;
		arr[3] = 1;
		arr[4] = 5;
		arr[5] = 9;
		arr[6] = 3;
		arr[7] = 4;
		arr[8] = 8;
	}
	else if (boardNumber == 4)
	{
		Board b;
		int num = 0;
		b.makeBoard(2);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				arr[num] = b.board[i][j];
				num++;
			}
		}
	}
	
	int number = 0;
	
	//Two dimentional array to set initial values in board
	Board board;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board.board[i][j] = arr[number];
			number++;
		}
	}
	return board;
}

BoardObject* returnBoards(Queue myQueue, Board b)
{
	Board temp;
	temp = b;
	BoardObject *arr = new BoardObject[12];//BoardObject *arr = new BoardObject[12];
	int num = 0;

	for (int i = 0; i < 3; i++)
	{
		temp.rotateNorth(i);
		arr[num].setBoard(temp);
		arr[num].setLocation("=>North Col " + to_string(i));
		temp = b;
		num++;

		temp.rotateSouth(i);
		arr[num].setBoard(temp);
		arr[num].setLocation("=>South Col " + to_string(i));
		temp = b;
		num++;

		temp.rotateEast(i);
		arr[num].setBoard(temp);
		arr[num].setLocation("=>East Row " + to_string(i));
		temp = b;
		num++;

		temp.rotateWest(i);
		arr[num].setBoard(temp);
		arr[num].setLocation("=>West Row " + to_string(i));
		temp = b;
		num++;
	}
	return arr;
}

void gameLogic(Queue myQueue, BoardObject b)
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

	int currentState = 1;
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

		//delete it from queue
		myQueue.Delete();

		//Get the rotations
		BoardObject *boardObjArr = returnBoards(myQueue, parentBoard);
		if (!win)
		{
			for (int i = 0; i < 12; i++)
			{
				BoardObject childObj;

				Board childBoard = boardObjArr[i].getBoard();
				childObj.setBoard(childBoard);

				childObj.setTier(prev);
				childObj.setSequence(currentState);

				string prevLocation = parentObj.getLocation();
				string currentMove = boardObjArr[i].getLocation();

				childObj.setLocation(currentMove + " " + prevLocation);
				myQueue.Insert(childObj);
				

				if (childBoard == winningBoard)
				{
					childObj.printObj();
					cout << "YOU WIN!! Original Board" << endl;
					Board winningB = b.getBoard();
					cout << winningB.toString();

					win = true;
					return;
				}
				else
				{
					childObj.printObj();
				}

				currentState++;
			}prev++;
		}		
	}
}


