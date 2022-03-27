#include<iostream>
using namespace std;

void SelectionSort(int *a,int n,int *c)
{
    for(int i=0;i<n-1;i++)
    {
        int index=i;
        for(int j=i+1;j<n;j++)
        {
            (*c)++;
            if(a[j]<a[index])
            {
                index=j;
            }
        }
        swap(a[i],a[index]);
    }
}
int main()
{
    int a[10]={9,6,3,0,1,4,7,2,5,3};
    int c=0;
    SelectionSort(a,10,&c);
    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
    cout<<"\nTotal number of comparision are: "<<c;
    return 0;
}
