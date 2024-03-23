#include <iostream>
#include <cstdlib>
using namespace std;

class TicTacToe
{
    char board[3][3];
    char currentPlayer;
    bool gameOver;

public:
    TicTacToe()
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                board[i][j] = ' ';
            }
        }
        currentPlayer = 'X';
        gameOver = false;
    }
    void displayBoard()
    {
        cout << "-------------" << endl;
        for (int i = 0; i < 3; ++i)
        {
            cout << "| ";
            for (int j = 0; j < 3; ++j)
            {
                cout << board[i][j] << " | ";
            }
            cout << endl;
            cout << "-------------" << endl;
        }
    }
    void getPlayerMove()
    {
        int row, col;
        cout << "Player " << currentPlayer << ", Enter Your Row and Column (e.g 1 1 is the first postion): " << endl;
        cin >> row >> col;
        row--;
        col--;
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ')
        {
            cout << "You Can't Place There, Reenter" << endl;
            getPlayerMove();
        }
        else
        {
            board[row][col] = currentPlayer;
        }
    }
    bool checkWin()
    {
        for (int i = 0; i < 3; ++i)
        {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;
        return false;
    }
    bool checkDraw()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                    return false;
            }
        }
        return true;
    }
    void switchPlayer()
    {
        if (currentPlayer == 'X')
        {
            currentPlayer = 'O';
        }
        else
        {
            currentPlayer = 'X';
        }
    }
    void play()
    {
        while (!gameOver)
        {
            system("cls");
            displayBoard();
            getPlayerMove();
            if (checkWin())
            {
                system("cls");
                displayBoard();
                cout << "Player " << currentPlayer << " WINS" << endl;
                gameOver = true;
            }
            else if (checkDraw())
            {
                system("cls");
                displayBoard();
                cout << "IT'S A DRAW" << endl;
                gameOver = true;
            }
            else
            {
                switchPlayer();
            }
        }
    }
};
int main()
{
    TicTacToe game;
    game.play();
}
