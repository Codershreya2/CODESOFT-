#include <iostream>
#include <vector>
using namespace std;
char board[3][3] = {{' ', ' ',' '}, {' ', ' ', ' '}, {' ', ' ', ' ',}};
char currentPlayer = 'X';
void displayBoard() {
    cout << " 1 2 3" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
        }
    }
    bool checkWin() {
        //Check rows
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
                return true;
            }
        }
        // Check columns
        for (int i = 0; i < 3; i++) {
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
                return true;
            }
        }
        // Check diagonals
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
            return true;
        }
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
            return true;
        }
        return false;
    }
    bool checkDraw() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }
    void switchPlayer() {
        if (currentPlayer == 'X') {
            currentPlayer = '0';
        } else {
            currentPlayer = 'X';
        }
        }
        int main() {
            int row, col;
            while (true) {
                displayBoard();
                cout << "Player " << currentPlayer << ", enter your move (row, column): ";
                cin >> row >> col;
                if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
                    cout << "Invalid move. Try again." << endl;
                    continue;
                }
                board[row - 1][col - 1] = currentPlayer;
                if (checkWin()) {
                    displayBoard();
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    break;
                }
                if (checkDraw()) {
                    displayBoard();
                    cout << "It's a draw!" << endl;
                    break;
                }
                switchPlayer();
            }
            return 0;
        }