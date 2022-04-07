#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,key;
    cin>>n>>key;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    int f=0,a=0,b=n-1;
    while(a<b)
    {
        if(v[a]+v[b]==key)
        {
            f=1;
            cout<<v[a]<<" "<<v[b]<<endl;
            a++;
            b--;
        }
        else if(v[a]+v[b]>key)
            b--;
        else
            a++;
    }
    if(f==0)
        cout<<"No such elements exists.";
    return 0;
}
