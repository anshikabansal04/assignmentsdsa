#include<iostream>
using namespace std;
void bubblesort(int arr[],int n){
	for(int j=0;j<n;j++){
	for(int i=0;i<n-j-1;i++){
		if(arr[i]>arr[i+1]){
			int temp;
			temp=arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=temp;
		}
	}
}
		for(int i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
	
}
int main(){
	int arr[90];
	int n;
	cout<<"enter size:";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"enter elemnt:";
		cin>>arr[i];
	}
	cout<<"before bubble sort:"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
	cout<<"after bubble sort"<<endl;
	bubblesort(arr,n);
	return 0;
}
