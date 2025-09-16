#include<iostream>
using namespace std;
void binary(int n){
    int arr[32];
    for(int i=1;i<=n;i++){
int gd=0;
int x=i;
while(x>0){
    arr[gd]=x%2;
    x=x/2;
    gd++;
}
    for(int i=gd-1;i>=0;i--){
        cout<<arr[i];
    }
    cout<<endl;
}
}
int main(){
    int n;
    cout<<"enter upto where user wants"<<endl;
    cin>>n;
    binary(n);
    return 0;
}
