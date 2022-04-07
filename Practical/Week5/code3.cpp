#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    int x=0,y=0;
    vector<int> ans;
    while(x!=n && y!=m)
    {
        if(x!=0 && a[x]==a[x-1])continue;
        if(y!=0 && b[y]==b[y-1])continue;
        if(a[x]==b[y])
        {
            ans.push_back(a[x]);
            x++;
            y++;
        }
        else if(a[x]>b[y])
        {
            y++;
        }
        else
        {
            x++;
        }
    }
    n=ans.size();
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    return 0;
}
