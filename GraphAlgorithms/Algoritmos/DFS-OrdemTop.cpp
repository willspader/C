#include <iostream>
#include <list>
#include <vector>

#define MAX 100

using namespace std;

int npre = 1, npos = 1;
int pre[MAX], pos[MAX];
list<int> top;
vector<int> adj[MAX];

void dfs(int v);

int main()
{
    int c, p, x, y;
    cin >> c >> p;

    for(int i = 0; i < p; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for(int i = 1; i <= c ; i++)
    {
        pre[i] = -1;
    }
    dfs(1);
}

void dfs(int v)
{
    pre[v] = npre++;
    for(int w: adj[v])
    {
        if(pre[w] == -1) dfs(w);
    }
    top.push_front(v);
    pos[v] = npos++;
}
