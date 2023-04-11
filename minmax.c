#include <stdio.h>

int max, min;
int arr[100];

void findMinMax(int i, int j)
{
  int mid, max1, min1;

  if (i == j)
  {
    max = arr[i];
    min = arr[i];
  }
  else if (j == i + 1)
  {
    if (arr[i] < arr[j])
    {
      max = arr[j];
      min = arr[i];
    }
    else
    {
      max = arr[i];
      min = arr[j];
    }
  }
  else
  {
    mid = (i + j) / 2;
    findMinMax(i, mid);
    max1 = max;
    min1 = min;
    findMinMax(mid + 1, j);
    if (max < max1)
    {
      max = max1;
    }
    if (min > min1)
    {
      min = min1;
    }
  }
}

int main()
{
  int n, i;

  printf("Enter size of array: ");
  scanf("%d", &n);

  printf("Enter elements:\n");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  max = arr[0];
  min = arr[0];
  findMinMax(0, n - 1);

  printf("Maximum element is %d\n", max);
  printf("Minimum element is %d\n", min);

  return 0;
}
