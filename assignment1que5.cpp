#include<iostream>
using namespace std;
void sum(int arr[][10],int rows,int coloums){
	
		for(int i=0;i<rows;i++) {
			int rowsum=0;
		for(int j=0;j<coloums;j++){
			rowsum=rowsum+arr[i][j];
}
cout<<"sum of rows"<<i<<"is"<<rowsum<<endl;
}
		for(int j=0;j<coloums;j++) {
			int coloumsum=0;
		for(int i=0;i<rows;i++){
			coloumsum=coloumsum+arr[i][j];
}
cout<<"sum of coloums "<<j<<"is"<<coloumsum<<endl;
}
}
int main(){
	int arr[10][10];
		int rows;
	int coloums;
	cout<<"enter number of rows:"<<endl;
	cin>>rows;
	cout<<"enter number of coloums:"<<endl;
	cin>>coloums;
	for(int i=0;i<rows;i++) {
		for(int j=0;j<coloums;j++){
			cout<<"enter element:"<<endl;
			cin>>arr[i][j];
		}
		cout<<endl;
	}
		
sum(arr,rows,coloums);
return 0;
}
