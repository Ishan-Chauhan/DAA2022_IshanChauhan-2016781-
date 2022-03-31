#include<bits/stdc++.h>
using namespace std;

void Merge(vector<int>& v,int p,int mid,int mid1,int q)
{
    vector<int> temp;
	int i=p,j=mid1;
	while(i!=mid+1 && j!=q+1)
	{
		if(v[i]<v[j])
		{
			temp.push_back(v[i]);
			i++;
		}
		else
		{
			temp.push_back(v[j]);
			j++;
		}
	}
	while(i!=mid+1)
	{
		temp.push_back(v[i]);
		i++;
	}
	while(j!=q+1)
	{
		temp.push_back(v[j]);
		j++;
	}
	int c=0;
	for(int i=p;i<=q;i++)
	{
		v[i]=temp[c];
		c++;
	}
}

void MergeSort(vector<int>& v,int p,int q)
{
    if(p==q)
		return;
	int mid=(p+q)/2;
	MergeSort(v,p,mid);
	MergeSort(v,mid+1,q);
	Merge(v,p,mid,mid+1,q);
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
    MergeSort(v,0,n-1);
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    return 0;
}
