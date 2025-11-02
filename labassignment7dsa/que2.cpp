#include<iostream>
using namespace std;
void selectionsort(int arr[],int n){
        int start=0;
        int end=n-1;
        while(start<end){
        int min=start;
        int max=start;
    for(int i=start;i<=end;i++){
           if(arr[i]<arr[min]){
min=i;
            }
            if(arr[i]>arr[max]){
                max=i;
            }
        }
                int temp=arr[start];
                arr[start]=arr[min];
                arr[min]=temp;
                if(max==start){
                    max=min;
                }
                temp=arr[end];
        arr[end]=arr[max];
        arr[max]=temp;
    start++;
    end--;
        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<endl;
        }
    }
    int main(){
        int arr[90];
        int n;
        cout<<"enter size"<<endl;
        cin>>n;
        for(int i=0;i<n;i++){
            cout<<"enter element"<<endl;
            cin>>arr[i];
        }
        selectionsort(arr,n);
        return 0;
    }