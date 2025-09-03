#include<iostream>
using namespace std;
int  Linear(int arr[],int n){
	int missing;
   int expectedsum = n*(n+1)/2;
    int actualsum = 0;
    for (int i=0;i<n-2;i++){   
        actualsum = actualsum+arr[i];
    }
    missing = expectedsum - actualsum;
    return missing;
}
int main(){
	int arr[10];
	int n;
	cout<<"entersize:";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"enter element";
		cin>>arr[i];
	}
	int p=Linear(arr,n);
	cout<<p;
	return 0;
}


