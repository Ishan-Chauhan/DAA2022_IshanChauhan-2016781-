#include<bits/stdc++.h>
using namespace std;

void kthelement(vector<int> v,int k)
{
    sort(v.begin(),v.end());
	int c=1,n=v.size();
	for(int i=1;i<=n;i++)
	{
		if(c==k)
		{
			cout<<"kth smallest element: "<<v[i-1]<<endl;
			break;
		}
		if(i!=n && v[i]!=v[i+1])
			c++;
	}
	c=1;
	for(int i=n-2;i>=-1;i--)
	{
		if(c==k)
		{
			cout<<"kth largest element: "<<v[i+1];
			break;
		}
		if(i!=-1 && v[i]!=v[i+1])
			c++;
	}
}

int main()
{
    int n,k,x;
    cin>>n>>k;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    kthelement(v,k);
    return 0;
}
