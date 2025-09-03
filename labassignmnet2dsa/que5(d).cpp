#include<iostream>
using namespace std;
void uppertraingular(int arr[][10],int row,int col){
	int diagonal[10]={1,1,1};
	int upper[10]={3,4,5};
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(i<j){
				arr[i][j]=upper[i+j-1];
			}
			else if (i==j){
			arr[i][j]=diagonal[i];
			}
			else
			{
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
	uppertraingular(arr,row,col);
}
