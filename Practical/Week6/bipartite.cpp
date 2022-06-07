#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int a,int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void printGraph(vector<int> adj[],int V)
{
    for(int v=0;v<V;v++)
    {
        cout<<v;
        for(auto i: adj[v])
        {
            cout<<"->"<<i;
        }
        cout<<endl;
    }
}

int isBipartite(int V,vector<int> adj[])
{
    vector<int> col(V,-1);
    queue<pair<int,int>> q;
    for(int i=0;i<V;i++)
    {
        if(col[i]==-1)
        {
            col[i]=0;
            q.push({i,0});
            while(!q.empty())
            {
                pair<int,int> p=q.front();
                q.pop();
                int v=p.first;
                int c=p.second;
                for(auto x: adj[v])
                {
                    if(col[x]==c)
                        return 0;
                    if(col[x]==-1)
                    {
                        col[x] = (c)?0:1;
                        q.push({x,col[x]});
                    }
                }
            }
        }
    }
    return 1;
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    //printGraph(adj, V);
    if(isBipartite(V, adj))
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}
