#include<iostream>
#include<limits.h>

using namespace std;


void bellman_ford(int **g,int V,int s){
    int dist[V];
    int parent[V];
    bool shortpath[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        parent[i]=0;
    }
    dist[s]=0;
    for(int i=0;i<V-1;i++){
        for(int u=s;u<V;u++){
            for(int v=0;v<V;v++){
                if(dist[u]!=INT_MAX && g[u][v] && dist[v]>dist[u]+g[u][v]){
                    dist[v]=dist[u]+g[u][v];
                    parent[v]=u;
                }
            }
        }
    }

    for(int u=0;u<V;u++){
        for(int v=0;v<V;v++){
            if(g[u][v] && dist[v]>dist[u]+g[u][v]){
                cout<<"-ve cycle exist.";
                return;
            }
        }
    }

    for(int i=0;i<V;i++){
        cout<<"Node "<<i+1<<"  | Path: ";
        int j=i;
        while(j!=s){
            cout<<parent[j]+1<<"<-";
            j=parent[j];
        }
        cout<<" | Distance: "<<dist[i]<<endl;
    }
}

int main(){
    int v,s;
    cin>>v;
    int **g = new int*[v];
    for(int i=0;i<v;i++)
        g[i]= new int[v];

    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            cin>>g[i][j];
    cin>>s;
    bellman_ford(g,v,s-1);
    return 0;
}
