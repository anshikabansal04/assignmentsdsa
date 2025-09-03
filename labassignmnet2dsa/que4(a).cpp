#include<iostream>
#include<string.h>
using namespace std;
void concatenate(string str1,string str2,int n1,int n2){
	string str3;
for(int i=0;i<n1;i++){
	 str3.push_back(str1[i]);
}

for(int i=0;i<n2;i++){
 str3.push_back(str2[i]);
}
cout<<str3<<endl;
	
}
int main(){
	string str1;
	string str2;
	cout<<"enter string 1"<<endl;
	getline(cin,str1);
	cout<<"enter string 2"<<endl;
	getline(cin,str2);
	int n1=str1.length();
	int n2=str2.length();
	concatenate(str1,str2,n1,n2);
}
