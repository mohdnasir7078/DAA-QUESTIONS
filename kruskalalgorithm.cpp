#include <iostream>
#include <algorithm>
#include <vector>
#include<limits.h>
using namespace std;
vector<pair<int, pair<int, int>>> graph;
vector<pair<int, pair<int, int>>> result;
int parent[10000];
using namespace std;
void make(int i)
{
    parent[i] = i;
}
int find(int V)
{
    if (V == parent[V])
        return V;
    return find(parent[V]);
}
void Union(int a, int b, int i)
{

    a = find(a);
    b = find(b);

    if (a != b)
    {
        parent[b] = a;
        result.push_back(graph[i]);
    }
}
void Kruskal(int V)
{
    sort(graph.begin(), graph.end());

    int E = graph.size();
    int s, d, w;

    for (int i = 0; i < E; i++)
    {
        s = graph[i].second.first;
        d = graph[i].second.second;
        Union(s, d, i);
    }
}
int main()
{
    int V, E;
    cout << "Input Vertex and Edge :";
    cin >> V >> E;
    for (int i = 0; i < V; i++)
        make(i);
    for (int i = 0; i < E; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        graph.push_back(make_pair(w, make_pair(s, d)));
    }
    int sum = 0;
    Kruskal(V);
    for (int i = 0; i < result.size(); i++)
    {
        int w = result[i].first;
        cout << result[i].second.first << "->" << result[i].second.second << endl;
        sum = sum + w;
    }
    cout << "Minimum Sum is :" << sum;
    return 0;
}
