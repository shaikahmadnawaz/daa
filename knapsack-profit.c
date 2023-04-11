#include <stdio.h>

#define MAX_ITEMS 20

void knapsack(int n, float weights[], float profits[], float capacity)
{
  float result[MAX_ITEMS] = {0};
  float total_profit = 0;
  float remaining_capacity = capacity;
  int i;

  for (i = 0; i < n; i++)
  {
    if (weights[i] > remaining_capacity)
    {
      break;
    }
    else
    {
      result[i] = 1;
      total_profit += profits[i];
      remaining_capacity -= weights[i];
    }
  }

  if (i < n)
  {
    result[i] = remaining_capacity / weights[i];
    total_profit += result[i] * profits[i];
  }

  printf("\nResult array x is:");
  for (i = 0; i < n; i++)
  {
    printf("%f ", result[i]);
  }
  printf("\nProfit is: %f", total_profit);
}

void sort_items(int n, float weights[], float profits[], float ratios[])
{
  int i, j;
  float temp;

  for (i = 0; i < n; i++)
  {
    ratios[i] = profits[i] / weights[i];
  }

  for (i = 0; i < n; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (ratios[i] < ratios[j])
      {
        temp = ratios[j];
        ratios[j] = ratios[i];
        ratios[i] = temp;

        temp = weights[j];
        weights[j] = weights[i];
        weights[i] = temp;

        temp = profits[j];
        profits[j] = profits[i];
        profits[i] = temp;
      }
    }
  }
}

int main()
{
  float weights[MAX_ITEMS], profits[MAX_ITEMS], ratios[MAX_ITEMS];
  float capacity;
  int n, i;

  printf("Enter the capacity of knapsack: ");
  scanf("%f", &capacity);

  printf("Enter the total number of objects: ");
  scanf("%d", &n);

  if (n <= 0 || n > MAX_ITEMS)
  {
    printf("Invalid number of objects.\n");
    return 1;
  }

  printf("Enter the weights and profits of each object:\n");
  for (i = 0; i < n; i++)
  {
    scanf("%f %f", &weights[i], &profits[i]);
  }

  sort_items(n, weights, profits, ratios);
  knapsack(n, weights, profits, capacity);

  return 0;
}
