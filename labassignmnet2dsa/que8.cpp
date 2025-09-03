#include<iostream>
using namespace std;
void  distinct(int arr[],int n){
	int count=0;
	int brr[30];
	for(int i=0;i<n;i++){
		bool check=true;
		for(int j=0;j<i;j++){
		if(arr[i]==arr[j]){
			check=false;
			break;
			}
		}
			if(check==true){
		count++;
	}
	}
	cout<<"count is:"<<count<<endl;
}
	
int main(){
	int arr[90];
	int n;
	cout<<"enter size";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"enter elemnt:";
		cin>>arr[i];
	}
	distinct( arr, n);
}
