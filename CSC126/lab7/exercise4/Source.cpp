#include<iostream>
using namespace std;
const int DIM = 3;
char chessboard[DIM][DIM];
void initChessBoard(char cb[][DIM])
{
	for (int row = 0; row < DIM; row++)
	{
		for (int col = 0; col < DIM; col++)
		{
			cb[row][col] = ' ';
		}
	}
}

void printChessBoard(char cb[][DIM])
{
	cout << "\n";
	for (int row = 0; row < DIM; row++)
	{
		for (int col = 0; col < DIM; col++)
		{
			if (col == 2)
			{
				cout << cb[row][col] << "\n";
			}
			else
			{
				cout << cb[row][col] << " | ";
			}
		}
	}
}

bool putChequer(char cb[][DIM], int i, int j, char c)
{
	if ((i <= 3 && i >= 1) && (j <= 3 && j >= 1)) {
		if (cb[i - 1][j - 1] == ' ') {
			cb[i - 1][j - 1] = c;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool state(char cb[][DIM], int row, int col, char c)
{
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
	for (int i = 0; i < DIM; i++)
	{
		if (cb[row-1][i] == c) {
			count1++;
		}

		if (cb[i][col-1] == c) {
			count2++;
		}

		if (cb[i][i] == c) {
			count3++;
		}

		if (cb[i][DIM - 1 - i] == c) {
			count4++;
		}
	}
	return (count1 == DIM || count2 == DIM || count3 == DIM || count4 == DIM);
}

int main()
{
	int row, col;
	int blanks = DIM * DIM;
	initChessBoard(chessboard);
	printChessBoard(chessboard);
	char cur = 'O';
	cout << "Input the position(row col), (-1 -1) for exit; It is the turn of " << cur << endl;
	cin >> row >> col;
	while (row != -1 && col != -1)
	{
		if (!putChequer(chessboard, row, col, cur))
		{
			cout << "Invalid move" << endl;
			printChessBoard(chessboard);
		}
		else
		{
			--blanks;
			printChessBoard(chessboard);
			if (state(chessboard, row, col, cur))
			{
				cout << cur << " Wins" << endl;
				system("pause");
				return 0;
			};
			if (blanks == 0)
			{
				cout << "Tie" << endl;
				system("pause");
				return 0;
			}
			if (cur == 'X')
				cur = 'O';
			else cur = 'X';
		}
		cout << "Input the position(row col), (-1 -1) for exit; It is the turn of " << cur << endl;
		cin >> row >> col;
	}
}