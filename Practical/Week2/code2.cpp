#include<iostream>
using namespace std;
int bs(int *a,int key,int l,int r)
{
    if(r<l)
        return -1;
    int mid=(l+r)/2;
    if(a[mid]==key)
    {
        return mid;
    }
    else if(a[mid]>key)
    {
        return bs(a,key,l,mid-1);
    }
    else
    {
        return bs(a,key,mid+1,r);
    }
}
int main()
{
    int n,i,j,k;
    cin>>n;
    int *a =new int[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n-2;i++)
    {
        for(j=i+1;j<n-1;j++)
        {
            if(bs(a,a[i]+a[j],0,n-1)!=-1)
                cout<<i<<" "<<j<<" "<<bs(a,a[i]+a[j],0,n-1)<<endl;
        }
    }
    return 0;
}
