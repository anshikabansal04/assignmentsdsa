#include<iostream>
using namespace std;
void bubblesot(int arr[],int n){
    int size=n-1;
    for(int i=0;i<size;i++){
         bool flag=true;
        for(int j=0;j<n-1-i;j++){
        if(arr[j]>arr[j+1]){
            flag=false;
            int temp;
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
  
     if(flag==true)
        break;
  }
    cout<<"sorted aaray";
  for(int i=0;i<=size;i++){
    cout<<arr[i]<<endl;
  }
  cout<<"";

}
int main(){
    int arr[90];
    int n;
    cout<<"enter size:"<<endl;
    cin>>n;
      for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bubblesot(arr,n);
return 0;
}
