#include <iostream>
using namespace std;

int bs(int *a,int key,int l,int r,int *c)
{
    if(r<l)
        return -1;
    int mid=(l+r)/2;
    if(a[mid]==key)
    {
        (*c)++;
        return mid;
    }
    else if(a[mid]>key)
    {
        (*c)++;
        return bs(a,key,l,mid-1,c);
    }
    else
    {
        (*c)++;
        return bs(a,key,mid+1,r,c);
    }
}

int main()
{
    int t,i=0,n,key,c=0,x;
    cin>>t;
    int ans[t];
    string s[t];
    while(i!=t)
    {
        c=0;
        cin>>n;
        int *a= new int[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        cin>>key;
        x=bs(a,key,0,n,&c);
        if(x==-1)
        {
            s[i]="Not Present";
            ans[i]=c;
        }
        else
        {
            s[i]="Present";
            ans[i]=c;
        }
        i++;
    }
    for(int i=0;i<t;i++)
        cout<<s[i]<<" "<<ans[i]<<endl;
    return 0;
}
