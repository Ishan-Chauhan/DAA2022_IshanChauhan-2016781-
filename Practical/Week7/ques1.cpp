#include<iostream>
#include<limits.h>

using namespace std;

int minDistance(int V,int dist[],bool shortpath[]){
    int min= INT_MAX,m_index;
    for(int v=0;v<V;v++){
        if(!shortpath[v]&&dist[v]<=min){
            min=dist[v];
            m_index=v;
        }
    }
    return m_index;
}


void dijkstra(int **g,int V,int s){
    int dist[V];
    int parent[V];
    bool shortpath[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        shortpath[i]=false;
        parent[i]=0;
    }
    dist[s]=0;
    for(int i=0;i<V;i++){
        int u=minDistance(V,dist,shortpath);
        shortpath[u]=true;
        for(int v=0;v<V;v++){
            if(!shortpath[v] && g[u][v] && dist[v]>dist[u]+g[u][v]){
                dist[v]=dist[u]+g[u][v];
                parent[v]=u;
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
    dijkstra(g,v,s-1);
    return 0;
}
