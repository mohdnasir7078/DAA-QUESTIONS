#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> qu;
    int visited[5] = {0, 0, 0, 0, 0};
    int arr[5][5] = {
        {1, 1, 1, 1, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 1, 0},
    };
    int i = 0, node;
    cout << "path : " << i << "->";
    visited[i] = 1;
    qu.push(i);
    while (!qu.empty())
    {
        node = qu.front();
        qu.pop();
        for (int j = 0; j < 5; j++)
        {
            if (arr[node][j] == 1 && visited[j] == 0)
            {
                qu.push(j);
                visited[j] = 1;
                cout << j;
                if (j != 4)
                    cout
                        << "->";
            }
        }
    }

    return 0;
}