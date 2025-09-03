#include<iostream>
using namespace std;
void symmteric(int arr[][10],int row,int col){
	int diagonal[10]={4,5,6};
	int symelement[10]={3,6,8};
	for(int i=0;i<row;i++){
		for(int j=0;j<=i;j++){
			if(i==j){
					arr[i][j]=diagonal[i];
			}
			else {
		arr[i][j]=symelement[(i+j-1)%3];
			}
			arr[j][i]=arr[i][j];
		
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
	symmteric(arr,row,col);
}
