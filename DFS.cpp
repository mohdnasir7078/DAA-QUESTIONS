#include <iostream>
using namespace std;
void DFS(int arr[][5], int visited[], int i)
{
    cout << i << " ";
    visited[i] = 1;
    for (int j = 0; j < 5; j++)
    {
        if (arr[i][j] == 1 && visited[j] == 0)
            DFS(arr, visited, j);
    }
}
int main()
{
    int visited[5] = {0, 0, 0, 0, 0};
    int arr[5][5] = {
        {1, 1, 1, 1, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 1, 0},
    };
    DFS(arr, visited, 0);
    return 0;
}