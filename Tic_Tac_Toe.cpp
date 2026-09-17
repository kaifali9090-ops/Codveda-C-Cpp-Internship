#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// Display board
void displayBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "\n";
}

// Check winner
bool checkWin() {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return true;
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return true;
    }

    // Diagonals
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return true;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return true;

    return false;
}

// Check draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] >= '1' && board[i][j] <= '9')
                return false;
        }
    }

    return true;
}

int main() {
    int choice;
    char player = 'X';

    cout << "===== TIC-TAC-TOE =====" << endl;
    cout << "Player 1 = X" << endl;
    cout << "Player 2 = O" << endl;

    while (true) {
        displayBoard();

        cout << "Player " << player << ", enter position (1-9): ";
        cin >> choice;

        if (choice < 1 || choice > 9) {
            cout << "Invalid position! Try again." << endl;
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        // Check already occupied
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Position already occupied! Try again." << endl;
            continue;
        }

        board[row][col] = player;

        if (checkWin()) {
            displayBoard();
            cout << "Player " << player << " wins!" << endl;
            break;
        }

        if (checkDraw()) {
            displayBoard();
            cout << "Game Draw!" << endl;
            break;
        }

        // Change player
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    return 0;
}