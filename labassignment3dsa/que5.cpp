#include<iostream>
#include<stack>
#include<string>
using namespace std;
void evaluate(string str){
    stack<char>s;
    string post="";
    char ch;
    int count=0;
    for(int i=0;i<str.length();i++){
        ch=str[i];
         if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
            s.push(ch);
         }
         else if(ch=='+'||ch=='*'||ch=='/'||ch=='-'){
            if(s.size()<2){
                cout<<"error ivalid expression"<<endl;
                return ;
            }
            s.pop();
            s.pop();
            s.push('x');
        }
         else{
            continue;
        }
    }
     if(s.size()== 1){
        cout <<"Expression is valid"<< endl;
    } else {
        cout<<"Error:invalid expression"<<endl;
    }
}
    

int main(){
    string str;
    cout<<"enter string:"<<endl;
    getline(cin,str);
    evaluate(str);
}
