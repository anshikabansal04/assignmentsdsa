#include<iostream>
using namespace std;
void tridiagonal(int arr[][10],int row,int col){
	int diagonal[10]={4,5,6,8};
	int upper[10]={3,6,8};
	 int lower[10]={3,6,1};
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(j-i==1){
				arr[i][j]=upper[i];
			}
			else if(i==j){
			arr[i][j]=diagonal[i];
			}
			else if(i-j==1){
				arr[i][j]=lower[j];
			}
			else {
				arr[i][j]={0};
			}
		
		}
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
		cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
}
int main(){
	int arr[10][10];
	int row;
	int col;
	cout<<"enter rows:"<<endl;
	cin>>row;
	cout<<"enter coloum:"<<endl;
	cin>>col;
	tridiagonal(arr,row,col);
}
