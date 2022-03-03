#include <iostream>
using namespace std;

int ls(int *a,int n,int key,int *c)
{
    for(int i=0;i<n;i++)
    {
        (*c)++;
        if(a[i]==key)
            return i;
    }
    return -1;
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
        x=ls(a,n,key,&c);
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
