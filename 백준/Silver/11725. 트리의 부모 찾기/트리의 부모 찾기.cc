#include <iostream>
#include <vector>
using namespace std;
//int sie = 0; //sum identity element : 덧셈 항등원 
//int mie = 1; //multiple identity element : 곱셈 항등원

vector<int> adj[101010];
int par[101010];

void    dfs(int node, int p)
{
    par[node] = p;
    for(int i=0;i<adj[node].size();i++)
    {
        if (adj[node][i] == p)
            continue;
        dfs(adj[node][i], node);
    }
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int a, b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    for(int i=2;i<=n;i++)
    {
        cout<<par[i]<<'\n';
    }
    return 0;
}