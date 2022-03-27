#include<iostream>
using namespace std;

void bubbleSort(int *a,int n,int *c)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            (*c)++;
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main()
{
    int a[10]={9,6,3,0,1,4,7,2,5,3};
    int c=0;
    bubbleSort(a,10,&c);
    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
    cout<<"\nTotal number of comparision are: "<<c;
    return 0;
}
