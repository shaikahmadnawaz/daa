#include <stdio.h>

void optimalMerge(int n, int sizes[])
{
  int total_cost = 0;
  while (n > 1)
  {
    int min_index1 = 0, min_index2 = 1;
    if (sizes[min_index1] > sizes[min_index2])
    {
      int temp = min_index1;
      min_index1 = min_index2;
      min_index2 = temp;
    }
    for (int i = 2; i < n; i++)
    {
      if (sizes[i] < sizes[min_index1])
      {
        min_index2 = min_index1;
        min_index1 = i;
      }
      else if (sizes[i] < sizes[min_index2])
      {
        min_index2 = i;
      }
    }
    int cost = sizes[min_index1] + sizes[min_index2];
    total_cost += cost;
    sizes[min_index1] = cost;
    sizes[min_index2] = sizes[n - 1];
    n--;
  }
  printf("Total cost of optimal merge is %d", total_cost);
}

int main()
{
  int n;
  printf("Enter the number of files: ");
  scanf("%d", &n);
  int sizes[n];
  printf("Enter the sizes of files: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &sizes[i]);
  }
  optimalMerge(n, sizes);
  return 0;
}
