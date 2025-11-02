#include<iostream>
using namespace std;
int partion(int arr[],int s,int e){
    int pivot=arr[s];
    int cnt=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<pivot){
            cnt++;
        }
    }
    int pivotindex=s+cnt;
    swap(arr[pivotindex],arr[s]);
    int i=s;
    int j=e;
    while(i<pivotindex && j>pivotindex){
while(arr[i]<pivot){
    i++;
}
while(arr[j]>pivot){
    j--;
}
if(i<pivotindex && j>pivotindex){
    swap(arr[i++],arr[j--]);
}
    }
    return pivotindex;
}
void quicksort(int arr[],int s,int e){
    if(s>=e){
        return ;
    }
    int q=partion(arr,s,e);
    quicksort(arr,s,q-1);
    quicksort(arr,q+1,e);
    for(int i=0;i<=e;i++){
        cout<<arr[i];
    }
}
int main(){
    int n;
    cout<<"enter size:"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"enter element"<<endl;
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    return 0;
}