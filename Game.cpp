#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<string>& board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i * 3 + j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<string>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i * 3][0] == player && board[i * 3 + 1][0] == player && board[i * 3 + 2][0] == player) ||
            (board[i][0] == player && board[i + 3][0] == player && board[i + 6][0] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[4][0] == player && board[8][0] == player) ||
        (board[2][0] == player && board[4][0] == player && board[6][0] == player)) {
        return true;
    }

    return false;
}


// Function to check if the board is full
bool checkFull(const vector<string>& board) {
    for (const string& cell : board) {
        if (cell == " ") {
            return false;
        }
    }
    return true;
}

int main() {
    vector<string> board(9, " ");

    char currentPlayer = 'X';
    int move;
    bool gameover = false;

    while (!gameover) {
        printBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9 || board[move - 1] != " ") {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        board[move - 1] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameover = true;
        } else if (checkFull(board)) {
            printBoard(board);
            cout << "It's a tie!" << endl;
            gameover = true;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
