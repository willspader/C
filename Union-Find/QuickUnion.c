#include <stdio.h>

#define MAX 10

int id[MAX];
int sz[MAX];

int main()
{
    for(int i = 0; i < MAX; i++)
    {
        id[i] = i;
        sz[i] = 1;
    }
}

int root(int i)
{
    while(i != id[i])
    {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

int connected(int p, int q)
{
    return root(p) == root(q);
}

void unionn(int p, int q)
{
    int i = root(p);
    int j = root(q);
    if(i == j) return;
    if(sz[i] < sz[j])
    {
        id[i] = j;
        sz[j] += sz[i];
    }
    else
    {
        id[j] = i;
        sz[i] += sz[j];
    }
}
