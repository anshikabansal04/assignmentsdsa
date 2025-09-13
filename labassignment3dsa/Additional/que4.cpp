#include<iostream>
#include<stack>
using namespace std;
void warmer(int arr[],int n,int ans[]){
stack<int>s1;
for(int i=0;i<n;i++){
    while(!s1.empty() && arr[i]>arr[s1.top()]){
        int prev=s1.top();
        s1.pop();
        ans[prev]=i-prev;
    }
    s1.push(i);
}
   while(!s1.empty()){
    ans[s1.top()]=0;
    s1.pop();
}

}
int main(){
    int arr[90];
    int ans[90];
    int n;
    cout<<"enter size"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"enter elemnt"<<endl;
        cin>>arr[i];
    }
    warmer(arr,n,ans);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
