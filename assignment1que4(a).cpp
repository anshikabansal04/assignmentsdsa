#include<iostream>
using namespace std;
void reversearray(int arr[],int n){
		int start=0;
	int end=n-1;
	while(start<end){
		int temp=arr[start];
		arr[start]=arr[end];
		arr[end]=temp;
		start++;
		end--;
	}
	cout<<"reverse array is:"<<endl;
		for(int j=0;j<n;j++){
		cout<<arr[j]<<endl;
		;
	}
}
int main(){
	int arr[10];
	int n;
	cout<<"enter size of an array"<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"enter elements of an array"<<endl;
		cin>>arr[i];
	}
reversearray(arr,n);
	return 0;
	
}
