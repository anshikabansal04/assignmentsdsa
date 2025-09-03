#include<iostream>
#include<string.h>
using namespace std;
void reverse(string name,int n){
	int start=0;
	int end=n;
	while(start<=end){
		int temp;
		temp=name[start];
		name[start]=name[end];
		name[end]=temp;
		start++;
		end--;
	}
	name[n+1]='\0';
	cout<<name;
}
int main(){
	string name;
	cout<<"enter string";
	getline(cin,name);
	int n=name.length()-1;
	reverse(name,n);
	return 0;
}
