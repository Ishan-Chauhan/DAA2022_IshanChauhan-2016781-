#include<iostream>
#define INF 9999999

using namespace std;

void shortest_distance_matrix(int v,int g[][5]){
    int dist[v][v],i,j,k;
    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
            dist[i][j]=g[i][j];
    for(k=0;k<v;k++){
        for(i=0;i<v;i++){
            for(j=0;j<v;j++){
              if(dist[i][j]>dist[i][k]+dist[k][j]&&dist[i][k]!=INF && dist[k][j]!=INF)
                    dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            if(dist[i][j]==INF)
                cout<<"INF ";
            else
                cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int v = 5;

    int g[5][5] = { {0,10,5,5,INF},
                    {INF,0,5,5,5},
                    {INF,INF,0,INF,10},
                    {INF,INF,INF,0,20},
                    {INF,INF,INF,5,0} };
    shortest_distance_matrix(v,g);
    return 0;
}
