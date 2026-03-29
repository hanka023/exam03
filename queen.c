
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//-g -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer
//valgrind -s

void free_board(char **board, int board_size)
{
    int i;

    i = 0;
    while (i < board_size)
    {
        free(board[i]);
        ++i;
    }
    free (board);
    return;
}

char **make_board(int board_size)
{
    int i;
    int j;
    char **board;

    i = 0;
    board = malloc (sizeof (char *)  * (board_size ));
    if (!board)
        return (0);
    while (i < board_size)
    {
        j = 0;
        board[i] = malloc (sizeof(char) * (board_size + 1));
        board[i][board_size] = '\0';
        while (j < board_size)
        {
            ++j;
        }
        ++i;
    }
    return (board);
}

char **print_board(char **board, int board_size)
{
    int i;
    int j;

    i = 0;

    while (i < board_size)
    {
        j = 0;
        while (j < board_size)
        {
            printf("%c ", board[i][j]);
            ++j;
        }
        printf ("\n");
        ++i;
    }
    return (board);
}


char **clear_board(char **board, int board_size)
{
    int i;
    int j;

    i = 0;
  
    while (i < board_size)
    {
        j = 0;
        while (j < board_size)
        {
            board [i][j] = '.';
            printf("%c ", board[i][j]);
            ++j;
        }
        printf ("\n");
        ++i;
    }
    printf ("\n");
    return (board);
}

void x_column(char **board, int board_size, int a, int b)
{
    int i = a;
    int j = b;

    while (i < board_size)
    {
        if (board[i][j] == '.' )
            board[i][j] = '-';
        ++i;
    }
    return;
}

void x_diagonal(char **board, int board_size, int a, int b)
{
    int i = a;
    int j = b;

    while (i < board_size && j < board_size)
    {
        if (board[i][j] == '.')
            board[i][j] = '-';
        ++i;
        ++j;
    }
    return;
}

char **queen_to_board(char **board, int board_size)
{
    
    int i;
    int j;
    int x_col;
  
    i = 0;
    while (i < board_size)
    {
        j = 0;
        while (j < board_size)
        {
            if(board [i][j] == '.')
            {
                board[i][j] = 'Q';
                x_column(board, board_size, i, j);
                x_diagonal(board, board_size, i, j);
                ++j;
                while(j < board_size)
                {
                    if (board[i][j] == '.')
                        board[i][j] = '-';
                    ++j;
                }
            }
            ++j;
        }
        ++i;
    }
    return (board);
}

int main (int argc, char *argv[])
{
    int i;
    int j;
    int board_size;
    char **board;
    char *cols;

    if (argc !=2)
        return (0); 
    board_size = atoi(argv[1]);
    i = 0;
    j = 0;

    board = make_board(board_size);
    clear_board (board, board_size);
    queen_to_board(board, board_size);
    print_board(board, board_size);
    free_board(board, board_size);
    return(0);
}