#include <bits/stdc++.h>
using namespace std;
#define V 6
int minimumnodevertex(vector<int> weight, vector<bool> process)
{
    int vertex;
    int minimum = INT_MAX;
    for (int i = 0; i < V; i++)
    {
        if (minimum > weight[i] && process[i] == false)
        {
            minimum = weight[i];
            vertex = i;
        }
    }
    return vertex;
}
void findMST(int graph[V][V])
{
    vector<int> parent(V, -1);
    vector<int> weight(V, INT_MAX);
    vector<bool> process(V, false);
    weight[0] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        int minvertex = minimumnodevertex(weight, process);
        process[minvertex] = true;
        for (int j = 0; j < V; j++)
        {
            if (graph[minvertex][j] != 0 && process[j] != true && graph[minvertex][j] < weight[j])
            {
                weight[j] = graph[minvertex][j];
                parent[j] = minvertex;
            }
        }
    }
    for (int i = 1; i < V; ++i)
        cout << "U->V: " << parent[i] << "->" << i << "  wt = " << graph[parent[i]][i] << "\n";
}
int main()
{
    int graph[V][V] = {{0, 6, 0, 0, 0, 4},
                       {6, 0, 7, 3, 1, 5},
                       {0, 7, 0, 8, 9, 0},
                       {0, 0, 8, 0, 3, 0},
                       {0, 1, 9, 3, 0, 0},
                       {4, 5, 0, 0, 2, 0}};

    findMST(graph);
    return 0;
}