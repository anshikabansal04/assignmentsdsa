#include<iostream>
using namespace std;
void diagonalmatrix(int arr[][10],int row1,int col1){
	int diagonal[10]={1,1,1};
	for(int i=0;i<row1;i++){
		for(int j=0;j<col1;j++){
			if(i==j){
		arr[i][j]=diagonal[i];
			}
			else {
				arr[i][j]={0};
			}
		}
	}
		for(int i=0;i<row1;i++){
		for(int j=0;j<col1;j++){
		cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
		
}
int main(){
	int arr[10][10];
	int row1;
	int col1;
	cout<<"enter rows:"<<endl;
	cin>>row1;
	cout<<"enter coloum:"<<endl;
	cin>>col1;
	diagonalmatrix(arr,row1,col1);
}
