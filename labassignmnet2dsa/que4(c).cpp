#include<iostream>
#include<string.h>
using namespace std;
void removevowels(string str1,int n){
	string str3;
	int start=0;
	for(int i=0;i<=n;i++){
		if(str1[i]!='a'&& str1[i]!='e'&& str1[i]!='i'&& str1[i]!='o' && str1[i]!='u'){
		str3 += str1[i];  

		}
	}

	cout<<str3;
}
int main(){
	string str1;
	cout<<"enter string";
	getline(cin,str1);
	int n=str1.length()-1;
	removevowels(str1,n);
	return 0;
}
