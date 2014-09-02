#include <iostream>
#include "Board.h"

using namespace std;

/*Jennifer Balling
A00890700
CS 3, Assignment 1: Solve the number cubes*/

int main(){

	Board testBoard;
	int num = 9;
	
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			testBoard.board[i][j] = num;
			num--;
		}
	}
	string s = testBoard.toString();
	cout << s;
	

	return 0;
}