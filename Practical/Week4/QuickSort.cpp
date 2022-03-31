#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& v,int p,int q)
{
    int x=v[p],i=p;
    for(int j=i+1;j<=q;j++)
    {
        if(v[j]<x)
        {
            i+=1;
            swap(v[i],v[j]);
        }
    }
    swap(v[i],v[p]);
    return i;
}

void qs(vector<int>& v,int p,int q)
{
    if(p>=q)
        return;
    int x=partition(v,p,q);
    qs(v,p,x-1);
    qs(v,x+1,q);
}

int main()
{
    int n,x;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
	  cout<<endl;
    qs(v,0,n-1);
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    return 0;
}
