/* 

Sample test case 1:

Input:
4 // First line of input is the size of the Chess board (square grid
Output:
2 // No of ways possible to place queens in safe state

Sample test case 1:
Input:
2 // First line of input is the size of the Chess board (square grid
Output:
0 // No of ways possible to place queens in safe state

You just have to complete the function nQueen() with parameter passed n represents the n x n size of the chess board and function returns the total no of solutions feasible to place queens in safe state, and if the their solution is no solution exists then return 0. 

Constraints to be followed:
2 ≤ n ≤ 10

Instructions: To run your custom test cases strictly follow the input and output layout as mentioned in the visible sample test cases.

Sample Test Cases
Test case 1
2	
0	
Test case 2
3	
0*/


#include <stdio.h>
#include <stdbool.h>

#define MAX 10
int count = 0;

bool isSafe(int row, int col, int n, int board[]) {
	for (int i = 0; i < row; i++) {
		if (board[i] == col || 
			board[i] - i == col - row || 
			board[i] + i == col + row) {
			return false;
		}
	}
	return true;
}

void solveNQueen(int row, int n, int board[]) {
	if (row == n) {
		count++;
		return;
	}

	for (int col = 0; col < n; col++) {
		if (isSafe(row, col, n, board)) {
			board[row] = col;
			solveNQueen(row + 1, n, board);
		}
	}
}
int nQueen(int n) {
	count = 0;
	int board[MAX];
	solveNQueen(0, n, board);
	return count;
}
