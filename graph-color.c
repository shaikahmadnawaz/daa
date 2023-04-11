#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_COLORS 10

int num_nodes, num_edges;
int graph[MAX_NODES][MAX_NODES];
int colors[MAX_NODES];

bool is_safe(int node, int color)
{
  for (int i = 0; i < num_nodes; i++)
  {
    if (graph[node][i] && colors[i] == color)
    {
      return false;
    }
  }
  return true;
}

bool color_graph(int node, int num_colors)
{
  if (node == num_nodes)
  {
    return true;
  }
  for (int i = 1; i <= num_colors; i++)
  {
    if (is_safe(node, i))
    {
      colors[node] = i;
      if (color_graph(node + 1, num_colors))
      {
        return true;
      }
      colors[node] = 0;
    }
  }
  return false;
}

int main()
{
  printf("Enter the number of nodes and edges: ");
  scanf("%d%d", &num_nodes, &num_edges);

  printf("Enter the edges:\n");
  for (int i = 0; i < num_edges; i++)
  {
    int from, to;
    scanf("%d%d", &from, &to);
    graph[from][to] = graph[to][from] = 1;
  }

  int num_colors;
  printf("Enter the number of colors: ");
  scanf("%d", &num_colors);

  if (color_graph(0, num_colors))
  {
    printf("Colors assigned to nodes:\n");
    for (int i = 0; i < num_nodes; i++)
    {
      printf("%d -> %d\n", i, colors[i]);
    }
  }
  else
  {
    printf("No solution found!\n");
  }

  return 0;
}
