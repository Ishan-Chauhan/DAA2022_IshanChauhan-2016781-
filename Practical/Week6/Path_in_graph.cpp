#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int a,int b)
{
    adj[a].push_back(b);
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
    printGraph(adj, V);
    int s,d,f=0;
    cout<<"Enter source: ";
    cin>>s;
    cout<<"Enter Destination: ";
    cin>>d;
    for(auto i: adj[s])
    {
        if(i==d)
        {
            f=1;
            cout<<"Path Exists"<<endl;
        }
    }
    if(f==0)
    {
        cout<<"Path Doesn't Exists"<<endl;
    }
    return 0;
}
