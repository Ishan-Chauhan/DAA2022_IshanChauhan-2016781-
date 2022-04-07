#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<char> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    int c=1,s=0,index;
    for(int i=0;i<n-1;i++)
    {
        if(v[i]==v[i+1])
            c++;
        else
        {
            if(c>s)
            {
                s=c;
                index=i;
            }
            c=1;
        }
    }
    cout<<"Element with maximum occurance is: "<<v[index]<<endl;
    return 0;
}
