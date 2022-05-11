#include <iostream>
#include <stack>
using namespace std;
void DFS(int a[][6], int visited[], int i);
stack<int> st;
int main()
{
    int visited[6] = {0, 0, 0, 0, 0, 0};
    int a[6][6] = {
        {0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0},
    };
    DFS(a, visited, 0);
    for (int i = 0; i < 6; i++)
        if (visited[i] == 0)
            DFS(a, visited, i);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
void DFS(int a[][6], int visited[], int i)
{
    int j;
    visited[i] = 1;
    for (j = 0; j < 6; j++)
    {
        if (a[i][j] == 1 && visited[j] == 0)
            DFS(a, visited, j);
    }
    st.push(i);
}
