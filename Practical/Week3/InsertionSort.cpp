#include<iostream>
using namespace std;

void InsertionSort(int *a,int n,int *c)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1,key=a[i];
        while(j>=0 && a[j]>key)
        {
            (*c)++;
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int main()
{
    int a[10]={9,6,3,0,1,4,7,2,5,3};
    int c=0;
    InsertionSort(a,10,&c);
    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
    cout<<"\nTotal number of comparision are: "<<c;
    return 0;
}
