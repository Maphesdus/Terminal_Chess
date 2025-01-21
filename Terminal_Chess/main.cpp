#include <iostream>
#include <string.h>
#include <Windows.h>
using namespace std;

int BOARD_SIZE = 8;
enum pieceType { K, Q, B, N, R, P };
pieceType piece;

void printBoard();
ostream& operator<<(ostream& os, const pieceType piece);

int main() {
	cout << "Terminal Chess\n" << endl;

	cout << "K = KING | Q = QUEEN | B = BISHOP | N = KNIGHT | R = ROOK | P = PAWN" << endl;
	

	printBoard();



	return 0;
}


void printBoard() {
	int count = BOARD_SIZE;
	cout << "\n\t   A  B  C  D  E  F  G  H";
	for (int row = 0; row < BOARD_SIZE; row++) {
		cout << "\n\t" << count << " ";
		for (int column = 0; column < BOARD_SIZE; column++) {
			if (row <= 1 || row >= 6) {
				if (row == 0 || row == 7) {
					if (column == 0 || column == 7) { piece = R; }
					else if (column == 1 || column == 6) { piece = N; }
					else if (column == 2 || column == 5) { piece = B; }
					else if (column == 4) { piece = K; }
					else piece = Q;
				}

				else if (row == 1 || row == 6) {
					piece = P;
				}
				cout << "[" << piece << "]";
			}
			else
				cout << "[_]";
		}
		cout << " " << count;
		count--;
	}
	cout << "\n";
	cout << "\t   A  B  C  D  E  F  G  H" << endl;
}


ostream& operator<<(ostream& os, const pieceType piece)
{
	switch (piece)
	{
		case pieceType::K:
			os << "K";
			break;	

		case pieceType::Q:
			os << "Q";
			break;

		case pieceType::B:
			os << "B";
			break;

		case pieceType::N:
			os << "N";
			break;

		case pieceType::R:
			os << "R";
			break;

		case pieceType::P:
			os << "P";
			break;
	}

	return os;
}