#include <iostream>
#include <list>

#define MAX 100

using namespace std;

int npre = 1, npos = 1;
int pre[MAX], pos[MAX];
list<int>adj[MAX];

void DFS(int v);

int main()
{
    int v = 6, x, y;

    for(int i = 0; i < 9; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for(int i = 1; i <= v ; i++)
    {
        pre[i] = -1;
    }
    DFS(1);
    return 0;
}

void DFS(int v)
{
    pre[v] = npre++;
    for(int w: adj[v])
    {
        if(pre[w] == -1) DFS(w);
    }
    pos[v] = npos++;
}
