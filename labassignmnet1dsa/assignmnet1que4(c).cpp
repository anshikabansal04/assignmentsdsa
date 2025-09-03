#include<iostream>
using namespace std;
void transpos(int brr[][10],int rows,int coloums){
	int transpose[10][10];
		for(int i=0;i<rows;i++) {
		for(int j=0;j<coloums;j++){
	transpose[i][j]=brr[j][i];
		}
		cout<<endl;
	}
	cout<<"after transpose"<<endl;
		for(int i=0;i<rows;i++) {
		for(int j=0;j<coloums;j++){
      cout<<transpose[i][j];
		}
		cout<<endl;
	}
}
int main(){
	int brr[10][10];
	int transpose[10][10];
	int rows;
	int coloums;
	cout<<"enter number of rows:"<<endl;
	cin>>rows;
	cout<<"enter number of coloums:"<<endl;
	cin>>coloums;
	for(int i=0;i<rows;i++) {
		for(int j=0;j<coloums;j++){
			cout<<"enter element:"<<endl;
			cin>>brr[i][j];
		}
		cout<<endl;
	}
	cout<<"before tranpose"<<endl;
	for(int i=0;i<rows;i++) {
		for(int j=0;j<coloums;j++){
		cout<<brr[i][j];
		}
		cout<<endl;
	}
transpos(brr,rows,coloums);
	return 0;
}
