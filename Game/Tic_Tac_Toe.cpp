#include <iostream>
#include <limits>
using namespace std;

// Display the board
void displayBoard(const char board[3][3])
{
    cout << "\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "\n";
    cout << "     |     |     \n";
    cout << "\n";
}

// Check whether a player has won
bool checkWin(const char board[3][3], char player)
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
        {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == player &&
            board[1][j] == player &&
            board[2][j] == player)
        {
            return true;
        }
    }

    // Check main diagonal
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
    {
        return true;
    }

    // Check other diagonal
    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
    {
        return true;
    }

    return false;
}

// Check whether board is full
bool isBoardFull(const char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] >= '1' && board[i][j] <= '9')
            {
                return false;
            }
        }
    }

    return true;
}

// Make a move for a human player
void makePlayerMove(char board[3][3], char player)
{
    int position;

    while (true)
    {
        cout << "Player " << player << ", enter position (1-9): ";

        cin >> position;

        // Handle non-numeric input
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input! Please enter a number from 1 to 9.\n";
            continue;
        }

        if (position < 1 || position > 9)
        {
            cout << "Invalid position! Choose between 1 and 9.\n";
            continue;
        }

        int row = (position - 1) / 3;
        int col = (position - 1) % 3;

        // Check if position is available
        if (board[row][col] != 'X' && board[row][col] != 'O')
        {
            board[row][col] = player;
            break;
        }

        cout << "That position is already occupied. Try again.\n";
    }
}

// Minimax algorithm
int minimax(char board[3][3], bool isMaximizing)
{
    // Computer wins
    if (checkWin(board, 'O'))
    {
        return 10;
    }

    // Human wins
    if (checkWin(board, 'X'))
    {
        return -10;
    }

    // Draw
    if (isBoardFull(board))
    {
        return 0;
    }

    // Computer's turn
    if (isMaximizing)
    {
        int bestScore = -1000;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] >= '1' && board[i][j] <= '9')
                {
                    char original = board[i][j];

                    board[i][j] = 'O';

                    int score = minimax(board, false);

                    board[i][j] = original;

                    bestScore = max(bestScore, score);
                }
            }
        }

        return bestScore;
    }

    // Human's turn
    else
    {
        int bestScore = 1000;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] >= '1' && board[i][j] <= '9')
                {
                    char original = board[i][j];

                    board[i][j] = 'X';

                    int score = minimax(board, true);

                    board[i][j] = original;

                    bestScore = min(bestScore, score);
                }
            }
        }

        return bestScore;
    }
}

// Computer makes the best move
void computerMove(char board[3][3])
{
    int bestScore = -1000;
    int bestRow = -1;
    int bestCol = -1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] >= '1' && board[i][j] <= '9')
            {
                char original = board[i][j];

                board[i][j] = 'O';

                int score = minimax(board, false);

                board[i][j] = original;

                if (score > bestScore)
                {
                    bestScore = score;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }

    board[bestRow][bestCol] = 'O';

    cout << "Computer chose position "
         << (bestRow * 3 + bestCol + 1) << ".\n";
}

// Initialize board
void initializeBoard(char board[3][3])
{
    char position = '1';

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = position++;
        }
    }
}

// Player vs Player
char playerVsPlayer()
{
    char board[3][3];
    initializeBoard(board);

    char currentPlayer = 'X';

    while (true)
    {
        displayBoard(board);

        makePlayerMove(board, currentPlayer);

        if (checkWin(board, currentPlayer))
        {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins! \n";
            return currentPlayer;
        }

        if (isBoardFull(board))
        {
            displayBoard(board);
            cout << "It's a draw! \n";
            return 'D';
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

// Player vs Computer
char playerVsComputer()
{
    char board[3][3];
    initializeBoard(board);

    cout << "\nYou are X.\n";
    cout << "Computer is O.\n";

    while (true)
    {
        // Player's turn
        displayBoard(board);

        makePlayerMove(board, 'X');

        if (checkWin(board, 'X'))
        {
            displayBoard(board);
            cout << "You win! \n";
            return 'X';
        }

        if (isBoardFull(board))
        {
            displayBoard(board);
            cout << "It's a draw! \n";
            return 'D';
        }

        // Computer's turn
        cout << "\nComputer is thinking...\n";

        computerMove(board);

        if (checkWin(board, 'O'))
        {
            displayBoard(board);
            cout << "Computer wins! \n";
            return 'O';
        }

        if (isBoardFull(board))
        {
            displayBoard(board);
            cout << "It's a draw! \n";
            return 'D';
        }
    }
}

// Main function
int main()
{
    int choice;

    int xWins = 0;
    int oWins = 0;
    int draws = 0;

    cout << "====================================\n";
    cout << "       TIC-TAC-TOE GAME\n";
    cout << "====================================\n";

    while (true)
    {
        cout << "\n========== MAIN MENU ==========\n";
        cout << "1. Player vs Player\n";
        cout << "2. Player vs Computer\n";
        cout << "3. View Score\n";
        cout << "4. Exit\n";
        cout << "===============================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input! Please enter 1-4.\n";
            continue;
        }

        if (choice == 1)
        {
            char result = playerVsPlayer();

            if (result == 'X')
                xWins++;
            else if (result == 'O')
                oWins++;
            else
                draws++;
        }

        else if (choice == 2)
        {
            char result = playerVsComputer();

            if (result == 'X')
                xWins++;
            else if (result == 'O')
                oWins++;
            else
                draws++;
        }

        else if (choice == 3)
        {
            cout << "\n========== SCORE ==========\n";
            cout << "Player X Wins : " << xWins << "\n";
            cout << "Player O Wins : " << oWins << "\n";
            cout << "Draws         : " << draws << "\n";
            cout << "===========================\n";
        }

        else if (choice == 4)
        {
            cout << "\nThanks for playing! \n";
            break;
        }

        else
        {
            cout << "Invalid choice! Please choose 1-4.\n";
        }
    }

    return 0;
}