#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;
int shortest_path_k_edge(int **g,int v,int s,int d,int k){
    int s_path_weight[v][v][k+1];
    for(int e=0;e<=k;e++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                s_path_weight[i][j][e]=INT_MAX;

                if(e==0&&i==j)
                    s_path_weight[i][j][e]=0;

                if(e==1&&g[i][j])
                    s_path_weight[i][j][e]=g[i][j];

                if(e>1){
                    for(int a=0;a<v;a++){
                        if(g[i][a] && i!=a && j!=a && s_path_weight[a][j][e-1]!=INT_MAX)
                            s_path_weight[i][j][e] = min(s_path_weight[i][j][e],g[i][a]+s_path_weight[a][j][e-1]);
                    }
                }
            }
        }
    }
    return s_path_weight[s][d][k];
}

int main(){
    int v,s,d,k;
    cin>>v;
    int **g = new int*[v];
    for(int i=0;i<v;i++)
        g[i]= new int[v];

    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            cin>>g[i][j];
    cin>>s>>d>>k;
    int res = shortest_path_k_edge(g,v,s-1,d-1,k);
    if(res==INT_MAX)
        cout<<"NO PATH EXIST.";
    else
        cout<<"Weight of shortest path: "<<res;
    return 0;
}
