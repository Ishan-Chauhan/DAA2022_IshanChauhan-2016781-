#include<iostream>
#include<algorithm>

using namespace std;

struct knapsack{
    int value,weight;
};

bool compare(struct knapsack a,struct knapsack b){
    return ( (double)a.value/a.weight > (double)b.value/b.weight );
}

int item_no(int a[],int b[],int n, double val){
    for(int i=0;i<n;i++){
        if((double)b[i]/a[i]==val)
            return i;
    }
}

int main(){
    int n,i;
    cin>>n;
    int w[n],v[n];
    for(i=0;i<n;i++)
        cin>>w[i];
    for(i=0;i<n;i++)
        cin>>v[i];

    struct knapsack a[n];
    for(i=0;i<n;i++){
        a[i].weight = w[i];
        a[i].value  = v[i];
    }
    sort(a,a+n,compare);
    int k;
    float profit = 0;
    cin>>k;
    int temp=k;
    for(i =0;i<n;i++){
        if(k==0)
            break;
        if(k>a[i].weight){
            k = k - a[i].weight;
            profit = profit + a[i].value;
        }
        else{
            profit = profit + k* ((double)a[i].value/a[i].weight);
            k=0;
        }
    }
    cout<<"\n\nMaximum Profit: "<<profit<<endl;
    cout<<"\n\nItem  |  Weight\n";
    cout<<"---------------\n";
    for(int j=0;j<i-1;j++){
        cout<<item_no(w,v,n,(double)a[j].value/a[j].weight)+1<<"     |    "<<a[j].weight<<endl;
        temp-=a[j].weight;
    }
    cout<<item_no(w,v,n,(double)a[i-1].value/a[i-1].weight)+1<<"     |    "<<temp<<endl;
    return 0;
}
