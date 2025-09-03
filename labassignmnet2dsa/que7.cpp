#include<iostream>
using namespace std;
void inversion(int arr[],int n){
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j] && i<j){
			
				cout<<"("<<i<<","<<j<<")";
				count++;
			}
		}
		
	}
	cout<<"inversion pairs are in total"<<count<<endl;
}
int main(){
	int arr[90];
	int n;
	cout<<"enter size:";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"enter eleemnt:";
		cin>>arr[i];
	}
	inversion(arr,n);
	return 0;
}
