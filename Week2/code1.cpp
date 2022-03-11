#include<iostream>
using namespace std;

int main()
{
    int n,key,c=0;
    cin>>n;
    int *a= new int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>key;
    for(int i=0;i<n;i++)
    {
        if(a[i]==key)
            c++;
        if(a[i]>key)
            break;
    }
    if(c==0)
        cout<<"Not Present"<<endl<<-1<<endl;
    else
        cout<<"Present"<<endl<<c<<endl;
    return 0;
}
