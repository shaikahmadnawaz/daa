#include <stdio.h>

#define N 8

void print_board(int board[N][N])
{
  int i, j;
  for (i = 0; i < N; i++)
  {
    for (j = 0; j < N; j++)
    {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

int is_safe(int board[N][N], int row, int col)
{
  int i, j;

  // Check this row on left side
  for (i = 0; i < col; i++)
  {
    if (board[row][i])
    {
      return 0;
    }
  }

  // Check upper diagonal on left side
  for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
  {
    if (board[i][j])
    {
      return 0;
    }
  }

  // Check lower diagonal on left side
  for (i = row, j = col; j >= 0 && i < N; i++, j--)
  {
    if (board[i][j])
    {
      return 0;
    }
  }

  return 1;
}

int solve(int board[N][N], int col)
{
  int i;
  if (col >= N)
  {
    return 1;
  }

  for (i = 0; i < N; i++)
  {
    if (is_safe(board, i, col))
    {
      board[i][col] = 1;

      if (solve(board, col + 1))
      {
        return 1;
      }

      board[i][col] = 0;
    }
  }

  return 0;
}

int main()
{
  int board[N][N] = {{0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0}};

  if (solve(board, 0))
  {
    print_board(board);
  }
  else
  {
    printf("No solution found\n");
  }

  return 0;
}

#include <stdio.h>
#define N 8

int board[N][N];

// Function to print the chess board
void printBoard()
{
  int i, j;
  printf("  ");
  for (i = 0; i < N; i++)
    printf("%d ", i);
  printf("\n");
  for (i = 0; i < N; i++)
  {
    printf("%d ", i);
    for (j = 0; j < N; j++)
      printf("%d ", board[i][j]);
    printf("\n");
  }
}

// Function to check if a queen can be placed in the given cell
int isSafe(int row, int col)
{
  int i, j;
  for (i = 0; i < col; i++) // Check row on left side
    if (board[row][i])
      return 0;
  for (i = row, j = col; i >= 0 && j >= 0; i--, j--) // Check upper diagonal on left side
    if (board[i][j])
      return 0;
  for (i = row, j = col; j >= 0 && i < N; i++, j--) // Check lower diagonal on left side
    if (board[i][j])
      return 0;
  return 1;
}

// Recursive function to solve the N-Queens problem
int solve(int col)
{
  int i;
  if (col >= N) // Base case: All queens have been placed
    return 1;
  for (i = 0; i < N; i++)
  {
    if (isSafe(i, col))
    {                     // Check if the queen can be placed in this cell
      board[i][col] = 1;  // Place the queen in the cell
      if (solve(col + 1)) // Recurse to place the next queen
        return 1;
      board[i][col] = 0; // Backtrack if a solution cannot be found
    }
  }
  return 0;
}

int main()
{
  int i, j;
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      board[i][j] = 0;
  if (solve(0))
    printBoard();
  else
    printf("No solution found.");
  return 0;
}
