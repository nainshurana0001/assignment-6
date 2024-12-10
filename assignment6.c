#include <stdio.h>

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';

void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

int checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    return 0;
}

int checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O') return 0;
    return 1;
}

void makeMove() {
    int choice;
    printf("Player %c, enter a number (1-9): ", currentPlayer);
    scanf("%d", &choice);

    int row = (choice - 1) / 3, col = (choice - 1) % 3;
    if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        printf("Invalid move. Try again.\n");
        makeMove();
    } else {
        board[row][col] = currentPlayer;
    }
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    printf("Tic Tac Toe Game\n");
    displayBoard();

    while (1) {
        makeMove();
        displayBoard();
        if (checkWin()) {
            printf("Player %c wins!\n", currentPlayer);
            break;
        }
        if (checkDraw()) {
            printf("It's a draw!\n");
            break;
        }
        switchPlayer();
    }

    return 0;
}
