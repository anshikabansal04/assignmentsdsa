#include<iostream>
#include<stack>
using namespace std;
void smallest(int arr[],int n,int ans[]){
    stack<int>s1;
    for(int i=0;i<n;i++){
    while(!s1.empty() && s1.top()>=arr[i]){
        s1.pop();
    }
    if(s1.empty()){
        ans[i]= -1;
    }
    else{
        ans[i]=s1.top();
    }
    s1.push(arr[i]);
    }
}
int main(){
    int arr[90];
    int ans[90];
    int n;
    int n2;
    cout<<"enter size of an array"<<endl;
    cin>>n;
    n2=n;//ans has same size as of input array
    for(int i=0;i<n;i++){
        cout<<"entetr element in an array"<<endl;
        cin>>arr[i];
    }
    smallest(arr,n,ans);
    cout<<"nearset smaller elements are"<<endl;
    for(int i=0;i<n2;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
