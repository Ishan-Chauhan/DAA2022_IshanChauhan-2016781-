#include<iostream>
#include<algorithm>
#include<limits.h>

using namespace std;

int find(int i,int p[]){
    while(p[i]!=i)
        i=p[i];
    return i;
}

void union1(int i,int j,int p[]){
    int a=find(i,p);
    int b=find(j,p);
    p[a]=b;
}

int kruskals(int **g,int V){
    int res=0;
    int parent[V];
    for(int i=0;i<V;i++)
        parent[i]=i;
    int edge_count=0;
    while(edge_count<V-1){
        int min =INT_MAX,a=-1,b=-1;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(find(i,parent)!=find(j,parent)&&g[i][j]&&g[i][j]<min){
                    min=g[i][j];
                    a=i;
                    b=j;
                }
            }
        }
        union1(a,b,parent);
        res+=min;
        edge_count++;
    }
    return res;
}

int main()
{
    int v;
    cin>>v;
    int **g = new int*[v];
    for(int i=0;i<v;i++)
        g[i]=new int[v];

    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            cin>>g[i][j];

    cout<<"Minimum Spanning weight: "<<kruskals(g,v);

    return 0;
}
