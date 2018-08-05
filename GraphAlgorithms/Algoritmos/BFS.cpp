#include <iostream>
#include <deque>
#include <vector>

#define MAX 100

using namespace std;

typedef pair<int, int> pii;

int pre[MAX]; // vetor de distancia

vector <vector <int>> g;
vector<int>adj[MAX];

void bfs(int);

int main()
{
    return 0;
}

/*
// BFS basica
void bfs(int v)
{
    deque<int> dq;
    dq.push_back(v);
    pre[v] = 1;
    while(!dq.empty())
    {
        v = dq.front();
        dq.pop_front();
        for(int w: adj[v])
        {
            if(pre[w] == -1) // nao tem distancia definida ainda
            {
                pre[w] = 1;
                dq.push_back(w);
            }
        }
    }
}
*/

// BFS modificada para usos de distancia entre vertices
// algoritmo de caminho minimo para grafo sem peso nas arestas
void bfs(int v)
{
    deque<int> dq;
    dq.push_back(v);
    pre[v] = 0;
    while(!dq.empty())
    {
        v = dq.front();
        dq.pop_front();
        for(int w: adj[v])
        {
            if(pre[w] == -1) // nao tem distancia definida ainda
            {
                pre[w] = pre[v] + 1;
                dq.push_back(w);
            }
        }
    }
}
