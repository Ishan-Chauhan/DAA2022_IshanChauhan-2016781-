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
    int n,c=0,i,j,key;
    cin>>n;
    int *a =new int[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    cin>>key;
    for(i=0;i<n-1;i++)
    {
        if(bs(a,a[i]+key,i+1,n-1)!=-1)
            c++;
    }
    cout<<c<<endl;
    return 0;
}
