#include<iostream>
#include<algorithm>
#include<limits.h>

using namespace std;

int max_key(int key[],bool mstset[],int V){
    int max=INT_MIN,max_index;
    for(int v=0;v<V;v++){
        if(mstset[v]==false && key[v]>max)
            max= key[v],max_index = v;
    }
    return max_index;
}

int max_sum_MST(int **g,int V){
    int parent[V],key[V];
    bool mstset[V];
    for(int i=0;i<V;i++)
        key[i]=INT_MIN,mstset[i]=false;
    key[0]=0;
    parent[0]=-1;
    for(int c=0;c<V-1;c++){
        int u = max_key(key,mstset,V);
        mstset[u]=true;
        for(int v=0;v<V;v++){
            if(g[u][v]&&mstset[v]==false&&g[u][v]>key[v])
                parent[v]=u,key[v]=g[u][v];
        }
    }
    int sum=0;
    for(int i=1;i<V;i++){
        sum = sum + g[i][parent[i]];
    }
    return sum;
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

    cout<<"Maximum Spanning weight: "<<max_sum_MST(g,v);

    return 0;
}
