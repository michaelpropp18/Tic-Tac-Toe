#include <iostream>
#include <string>

void drawBoard();
void twoPlayer();
int checkForWinner();
char board[3][3];

int main ()
{
    std::string input;
    std::cout << "Welcome to TicTacToe!\n";
    for(int x = 0; x < 3; x++) {
        for(int y = 0; y < 3; y++) {
            board[x][y] = ' ';
        }
    }
    twoPlayer();
    return 0;
}

void twoPlayer() {
    int currentPlayer = 1;
    int winner = 0;
    while(winner == 0) {
        std::string input;
        while (input.length() > 1 || !(input.compare("0") > 0 && input.compare("9") <= 0)) {
            drawBoard();
            std::cout << "\n1|2|3\n4|5|6\n7|8|9\n";
            std::cout << "\nPlayer " << currentPlayer << ": Enter the number corresponding the square you would like to play\n";
            std::cin >> input;
        }
        int position = std::stoi(input) - 1;
        if (board[position / 3][position % 3] == ' ') {
            board[position / 3][position % 3] = currentPlayer == 1 ? 'X' : 'O';
            currentPlayer = currentPlayer == 1 ? 2 : 1;
            winner = checkForWinner();
        } 
    }
    drawBoard();
    if (winner == 3) {
        std::cout << "\nThe game is a draw!\n";
    } else {
        std::cout << "\nPlayer " << checkForWinner() << " wins!\n";
    }
}

int checkForWinner() { // 0 if none, 1 if player 1, 2 if player 2, 3 if draw
    if (board[1][1] != ' ') {
        if(board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            return board[0][0] == 'X' ? 1 : 2;
        } 
        if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return board[2][0] == 'X' ? 1 : 2;
        }
    }
    for(int i = 0; i < 3; i++) {
        if(board[i][i] != ' ') {
            if(board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
                return board[i][0] == 'X' ? 1 : 2;
            } else if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
                return board[0][i] == 'X' ? 1 : 2;
            }
        }
    }
    for(int x = 0; x < 3; x++) {
        for(int y = 0; y < 3; y++) {
            if (board[x][y] == ' ') {
                return 0;
            }
        }
    }
    return 3;
}

void drawBoard() {
    std::system("clear");
    for(int x = 0; x < 3; x++) {
        std::cout << "   |   |   \n";
        std::cout << " " << board[x][0] << " | " << board[x][1] << " | " << board[x][2] << "\n";
        std::cout << "   |   |   \n";
        if (x < 2) {
            std::cout << "---|---|---\n";
        }
    }
}

