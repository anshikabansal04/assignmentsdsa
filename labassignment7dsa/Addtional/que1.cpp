#include<iostream>
using namespace std;
int max(int arr[],int n){
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
void countedsort(int arr[],int n){
    int maxi=max(arr,n);
    int count[maxi+1]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<=maxi;i++){
        count[i]+=count[i-1];
    }
    int output[1000];
    for(int i=n-1;i>=0;i--){
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    } 
}
int main(){
    int arr[90];
    int n;
    cout<<"et\nter size of an array:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"enter element"<<endl;
        cin>>arr[i];
    }
    countedsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
         cout<<endl;
    return 0;
}
