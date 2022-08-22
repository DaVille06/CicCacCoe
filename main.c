#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 9

void drawBoard();
void markBoard(int selection);
_Bool checkForWin(int selection);
_Bool checkForDraw();

char gameBoard[BOARD_SIZE] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
_Bool currentPlayer = 0;
int currentTurn = 1;

int main()
{
    _Bool gameOver = 0;

    while (!gameOver)
    {
        _Bool selectionSuccessful = 0;
        int userSelection = 0;
        while (!selectionSuccessful)
        {
            //  draw board
            drawBoard();

            //  collect input
            printf("Player %d, enter a number: ", (currentPlayer + 1));
            scanf("%d", &userSelection);

            // make sure that selection is between 1 and 9
            // make sure that selection isn't already selected
            if ((userSelection >= 1 && userSelection <= 9) &&
                (gameBoard[userSelection - 1] != 'X' || gameBoard[userSelection - 1] != 'O'))
                selectionSuccessful = 1;
        }

        //  mark board
        markBoard(userSelection);

        //  check for win);
        if (checkForWin(userSelection))
        {
            drawBoard();
            printf("\n Player %d has won the game!\n", (currentPlayer + 1));
            gameOver = 1;
        }
        else if (checkForDraw())
        {
            drawBoard();
            printf("\n No player has won the game! It is a draw!\n");
            gameOver = 1;
        }
        else
        {
            if (currentPlayer) currentPlayer = 0;
            else currentPlayer = 1;

            currentTurn++;
        }
    }

    return 0;
}

void drawBoard()
{
    system("clear");
    printf("\n\tTic Tac Toe\n");
    printf("\nPlayer 1 (X) - Player 2 (O)\n");
    printf("\n   |   |\n");
    for (int i = 1; i < 4; i++)
    {
        printf(" %c ", gameBoard[i - 1]);

        if (i != 3)
            printf("|");
    }
    printf("\n");
    printf("___|___|___\n");
    printf("   |   |\n");
    for (int i = 4; i < 7; i++)
    {
        printf(" %c ", gameBoard[i - 1]);

        if (i != 6)
            printf("|");
    }
    printf("\n");
    printf("___|___|___\n");
    printf("   |   |\n");
    for (int i = 7; i < 10; i++)
    {
        printf(" %c ", gameBoard[i - 1]);

        if (i != 9)
            printf("|");
    }
    printf("\n");
    printf("   |   |\n");
}

void markBoard(int selection)
{
    if (currentPlayer == 0) { gameBoard[selection - 1] = 'X'; }
    else gameBoard[selection - 1] = 'O';
}

_Bool checkForWin(int selection)
{
    if (currentTurn < 4)
        return 0;

    switch (selection)
    {
    case 1:
        if ((gameBoard[0] == gameBoard[1] && gameBoard[0] == gameBoard[2]) ||
            (gameBoard[0] == gameBoard[3] && gameBoard[0] == gameBoard[6]) ||
            (gameBoard[0] == gameBoard[4] && gameBoard[0] == gameBoard[8]))
            return 1;
        break;
    case 2:
        if ((gameBoard[0] == gameBoard[1] && gameBoard[1] == gameBoard[2]) ||
            (gameBoard[1] == gameBoard[4] && gameBoard[1] == gameBoard[7]))
            return 1;
        break;
    case 3:
        if ((gameBoard[0] == gameBoard[2] && gameBoard[1] == gameBoard[2]) ||
            (gameBoard[2] == gameBoard[5] && gameBoard[2] == gameBoard[8]) ||
            (gameBoard[2] == gameBoard[4] && gameBoard[2] == gameBoard[6]))
            return 1;
        break;
    case 4:
        if ((gameBoard[3] == gameBoard[4] && gameBoard[3] == gameBoard[5]) ||
            (gameBoard[0] == gameBoard[3] && gameBoard[3] == gameBoard[6]))
            return 1;
        break;
    case 5:
        if ((gameBoard[3] == gameBoard[4] && gameBoard[4] == gameBoard[5]) ||
            (gameBoard[1] == gameBoard[4] && gameBoard[4] == gameBoard[7]) ||
            (gameBoard[0] == gameBoard[4] && gameBoard[4] == gameBoard[8]) ||
            (gameBoard[2] == gameBoard[4] && gameBoard[4] == gameBoard[6]))
            return 1;
        break;
    case 6:
        if ((gameBoard[3] == gameBoard[5] && gameBoard[4] == gameBoard[5]) ||
            (gameBoard[2] == gameBoard[5] && gameBoard[5] == gameBoard[8]))
            return 1;
        break;
    case 7:
        if ((gameBoard[0] == gameBoard[6] && gameBoard[3] == gameBoard[6]) ||
            (gameBoard[6] == gameBoard[7] && gameBoard[6] == gameBoard[8]) ||
            (gameBoard[2] == gameBoard[6] && gameBoard[4] == gameBoard[6]))
            return 1;
        break;
    case 8:
        if ((gameBoard[6] == gameBoard[7] && gameBoard[7] == gameBoard[8]) ||
            (gameBoard[1] == gameBoard[7] && gameBoard[4] == gameBoard[7]))
            return 1;
        break;
    case 9:
        if ((gameBoard[6] == gameBoard[8] && gameBoard[7] == gameBoard[8]) ||
            (gameBoard[2] == gameBoard[8] && gameBoard[5] == gameBoard[8]) ||
            (gameBoard[0] == gameBoard[8] && gameBoard[4] == gameBoard[8]))
            return 1;
        break;
    }

    return 0;
}

_Bool checkForDraw()
{
    if (currentTurn == 9)
        return 1;
    return 0;
}
