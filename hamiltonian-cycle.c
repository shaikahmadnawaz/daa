#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int n, graph[MAX][MAX], path[MAX];

void printSolution()
{
  int i;
  printf("Hamiltonian cycle: ");
  for (i = 0; i < n; i++)
  {
    printf("%d ", path[i]);
  }
  printf("%d", path[0]);
}

bool isSafe(int v, int pos)
{
  if (graph[path[pos - 1]][v] == 0)
  {
    return false;
  }
  int i;
  for (i = 0; i < pos; i++)
  {
    if (path[i] == v)
    {
      return false;
    }
  }
  return true;
}

bool hamCycleUtil(int pos)
{
  if (pos == n)
  {
    if (graph[path[pos - 1]][path[0]] == 1)
    {
      printSolution();
      return true;
    }
    return false;
  }
  int v;
  for (v = 1; v < n; v++)
  {
    if (isSafe(v, pos))
    {
      path[pos] = v;
      if (hamCycleUtil(pos + 1))
      {
        return true;
      }
      path[pos] = -1;
    }
  }
  return false;
}

void hamCycle(int start)
{
  int i;
  for (i = 0; i < n; i++)
  {
    path[i] = -1;
  }
  path[0] = start;
  if (!hamCycleUtil(1))
  {
    printf("No Hamiltonian cycle exists\n");
  }
}

int main()
{
  printf("Enter the number of vertices: ");
  scanf("%d", &n);
  int i, j;
  printf("Enter the adjacency matrix:\n");
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      scanf("%d", &graph[i][j]);
    }
  }
  hamCycle(0);
  return 0;
}
