// ConsoleApplication9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//RUSHIMISHA DIEUDONNE 222013223
//NIYONGABO JEAN 222005937
//uwihanganye Obed 222012223
#include <iostream>
using namespace std;

const int ROWS = 6;
const int COLS = 7;
const char PLAYER1 = 'A';
const char PLAYER2 = 'B';

int main() {
    // Initialize board
    char board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }

    int moves = 0;
    char current_player = PLAYER1;
    bool game_over = false;

    // Game loop
    while (!game_over) {
        // Print current state of board
        cout << endl;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                cout << "| " << board[i][j] << " ";
            }
            cout << "|" << endl;
        }
        cout << "-----------------------------" << endl;

        //  player moves are being taken now
        int col;
        do {
            cout << "Player " << current_player << ", enter Your column(1-7) to enter your "<< current_player <<" letter on the board: ";
            cin >> col;
            col--;
        } while (col < 0 || col >= COLS || board[0][col] != ' ');

        // he/she started moving on the board
        for (int i = ROWS - 1; i >= 0; i--) {
            if (board[i][col] == ' ') {
                board[i][col] = current_player;
                break;
            }
        }

        // Let's horizontally check whether he/she won the game
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS - 3; j++) {
                if (board[i][j] == current_player && board[i][j + 1] == current_player && board[i][j + 2] == current_player && board[i][j + 3] == current_player) {
                    cout << "Congratulations, Player " << current_player << " wins!" << endl;
                    game_over = true;
                    break;
                }
            }
        }

        // Let's verticaly check whether he/she won the game
        for (int i = 0; i < ROWS - 3; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == current_player && board[i + 1][j] == current_player && board[i + 2][j] == current_player && board[i + 3][j] == current_player) {
                    cout << "Congratulations, Player " << current_player << " wins!" << endl;
                    game_over = true;
                    break;
                }
            }
        }

         // Let's Diagonally (top-left to bottom-right) check whether he/she won the game
        for (int i = 0; i < ROWS - 3; i++) {
            for (int j = 0; j < COLS - 3; j++) {
                if (board[i][j] == current_player && board[i + 1][j + 1] == current_player && board[i + 2][j + 2] == current_player && board[i + 3][j + 3] == current_player) {
                    cout << "Congratulations, Player " << current_player << " wins!" << endl;
                    game_over = true;
                    break;
                }
            }
        }

        // Let's Diagonally (bottom-left to top-right) check whether he/she won the game
        for (int i = 3; i < ROWS; i++) {
            for (int j = 0; j < COLS - 3; j++) {
                if (board[i][j] == current_player && board[i - 1][j + 1] == current_player && board[i - 2][j + 2] == current_player && board[i - 3][j + 3] == current_player) {
                    cout << "Congratulations, Player " << current_player << " wins!" << endl;
                    game_over = true;
                    break;
                }
            }
        }

        // Switch our player over another in the game
        if (current_player == PLAYER1) {
            current_player = PLAYER2;
        }
        else {
            current_player = PLAYER1;
        }

        // Check for tie
        moves++;
        if (moves == ROWS * COLS && !game_over) {
            cout << "It's a tie!" << endl;
            game_over = true;
        }
    }

    return 0;
}
//then its done our game!!!!!
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
