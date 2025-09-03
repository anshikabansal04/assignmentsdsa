#include<iostream>
using namespace std;
int binarysearch(int arr[],int n,int key){
		int start=0;
	int end=n-1;
	while(start<=end){
			int mid=start+(end-start)/2;
			if(arr[mid]==key){
			return mid;
		}
			else if(key>arr[mid])
			{
				start=mid+1;
			}
			else
			{
				end=mid-1;
			}
	}
	return -1;
}
int main(){
	int arr[90];
	int n;
	int key;
	cout<<"enter key";
	cin>>key;
	cout<<"enter size of an array";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"enter element:";
		cin>>arr[i];
	}
	int result=binarysearch(arr,n,key);
	if(result!=-1){
	cout<<"at index"<<result<<endl;
	}
return 0;
}
