#include<iostream>
using namespace std;
void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
min=j;
            }
        }
            if(min!=i){
                int temp=arr[min];
                arr[min]=arr[i];
                arr[i]=temp;
            }
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
      for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
  selectionsort(arr,n);
return 0;
}