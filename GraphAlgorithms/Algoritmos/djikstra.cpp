#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <list>

#define INF 0x3f3f3f3f
#define MAX 100

using namespace std;

typedef pair<int, int> iPair;

int dist[MAX];
int n;
list< pair<int, int> > *adj;

void addEdge(int u, int v, int w);
void djikstra(int src);

int main()
{
    cin >> n; //number of vertices
    adj = new list<iPair>[n];

    addEdge(0, 7, 8);
    addEdge(0, 1, 4);
    addEdge(1, 2, 8);
    addEdge(1, 7, 11);
    addEdge(2, 3, 7);
    addEdge(2, 8, 2);
    addEdge(2, 5, 4);
    addEdge(3, 4, 9);
    addEdge(3, 5, 14);
    addEdge(4, 5, 10);
    addEdge(5, 6, 2);
    addEdge(6, 7, 1);
    addEdge(6, 8, 6);
    addEdge(7, 8, 7);

    djikstra(0);

    return 0;
}

void addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void djikstra(int src)
{
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

    vector<int> dist(n, INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d \t\t %d\n", i, dist[i]);
    }

}
