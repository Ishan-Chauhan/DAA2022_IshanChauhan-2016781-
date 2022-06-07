#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    int n,a;
    cin>>n;
    priority_queue<int ,vector<int>,greater<int>> minheap;
    for(int i=0;i<n;i++){
        cin>>a;
        minheap.push(a);
    }
    int res=0;
    while(minheap.size()>1){
        int e1 = minheap.top();
        minheap.pop();
        int e2 = minheap.top();
        minheap.pop();
        int temp=e1+e2;
        res+=temp;
        minheap.push(e1+e2);
    }
    cout<<res;
    return 0;
}
