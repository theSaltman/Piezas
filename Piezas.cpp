#include "Piezas.h"
#include <vector>
#include <iostream>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas() {
	turn = X;
	board.resize(BOARD_ROWS);
	std::cout << board.size() << std::endl;
	for (int i = 0; i < BOARD_ROWS; i++) {
		board[i].resize(BOARD_COLS);
		std::cout << board[i].size() << std::endl;
	}
	for (int i = 0; i < BOARD_ROWS; i++) {
		for (int j = 0; j < BOARD_COLS; j++) {
			board[i][j] = Blank;
			std::cout << board[i][j] << " " << i << " " << j << std::endl;
		}
	}
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset() {
/*	board.resize(BOARD_ROWS);
	for (int i = 0; i < BOARD_COLS; i++) {
		board[i].resize(BOARD_COLS);
	}*/
/*	for (int i = 0; i < BOARD_ROWS; i++) {
		for (int j = 0; j < BOARD_COLS; i++) {
			board[i][j] = Blank;
		}
	}*/
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column) {
	if (turn == X) {
		turn = O;
	} else {
		turn = X;
	}
	if (column > BOARD_COLS - 1 || column < 0) {
		return Invalid;
	}
	int found = 0;
	int loc = 0;
	for (int i = BOARD_ROWS - 1; i >= 0; i--) {
		if (board[i][column] == Blank) {
			found = 1;
			loc = i;
		}
	}
	if (found == 0) {
		return Blank;
	} else {
		if (turn == X) {
			board[loc][column] = O;
			return O;
		} else {
			board[loc][column] = X;
			return X;	
		}
	}
	
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column) {
	if (row >= BOARD_ROWS || row < 0 || column >= BOARD_COLS || column < 0) {
		return Invalid;
	}
    return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
	int Xcount = 0;
	int Ocount = 0;
	int Xvert = 0;
	int Xhor = 0;
	int Overt = 0;
	int Ohor = 0;
	int foundBlank = 0;
	for (int i = 0; i < BOARD_ROWS; i++) {
		for (int j = 0; j < BOARD_COLS; j++) {
			if (board[i][j] == Blank) {
				foundBlank = 1;
			}
			if (j == 0) {
				Xhor = 0;
				Ohor = 0;
				if (board[i][j] == X) {
					Xhor++;	
				} else {
					Ohor++;
				}
			} else {
				if (board[i][j] == board[i][j-1]) {
					if (board[i][j] == X) {
						Xhor++;
					} else {
						Ohor++;
					}
				} else {
					Xhor = 0;
					Ohor = 0;
					if (board[i][j] == X) {
						Xhor++;
					} else {
						Ohor++;
					}
				}
			}
			if (Xhor > Xcount) {
				Xcount = Xhor;
			} 
			if(Ohor > Ocount) {
				Ocount = Ohor;	
			}
		}
	}
	for (int i = 0; i < BOARD_COLS; i++) {
		for (int j = 0; j < BOARD_ROWS; j++) {
			if (board[j][i] == Blank) {
				foundBlank = 1;
			}
			if (j == 0) {
				Xvert = 0;
				Overt = 0;
				if (board[j][i] == X) {
					Xvert++;	
				} else {
					Overt++;
				}
			} else {
				if (board[j][i] == board[j-1][i]) {
					if (board[j][i] == X) {
						Xvert++;
					} else {
						Overt++;
					}
				} else {
					Xvert = 0;
					Overt = 0;
					if (board[j][i] == X) {
						Xvert++;
					} else {
						Overt++;
					}
				}
			}
			if (Xvert > Xcount) {
				Xcount = Xvert;
			} 
			if(Overt > Ocount) {
				Ocount = Overt;	
			}
		}
	}
	if (foundBlank > 0) {
		return Invalid;
	}
	if (Xcount == Ocount) {
		return Blank;
	}
	if (Xcount > Ocount) {
		return X;
	}
	if (Ocount > Xcount) {
		return O;
	}
}
