#include<iostream>
using namespace std;
void insertionsort(int arr[],int n){
    
    for(int i=1;i<n;i++){
        int temp=arr[i];
       int  j=i;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
    j--;
    }
     arr[j+1]=temp;
}
for(int i=0;i<n;i++){
    cout<<arr[i]<<endl;
}
}
int main(){
    int arr[90];
    int n;
    cout<<"enter size:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"enter element"<<endl;
        cin>>arr[i];
    }
    insertionsort(arr,n);
    return 0;
}