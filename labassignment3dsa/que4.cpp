#include<iostream>
#include<stack>
#include<string>
using namespace std;
int precendence(char op){
    if(op=='+'||op=='-') {return 1;}
    if(op=='*'||op=='/'){return 2;}
    return 0;
}
void convert(string str){
    stack<char>s;
    string postfix="";
    char ch;
    for(int i=0;i<str.length();i++){
        ch=str[i];
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
            postfix=postfix+ ch;
        }
       else  if(ch=='{'){
s.push(ch);
        }
        else if(ch=='}') {
            while(!s.empty() && s.top() != '{'){
                postfix=postfix+ s.top();
                s.pop();
            }
            if(!s.empty()){s.pop();}//remove left also
           
        }
        else if( ch=='+'||ch=='*'||ch=='/'||ch=='-'){
while(!s.empty() && precendence(s.top())>=precendence(ch)){
    postfix=postfix+s.top();
    s.pop();
    }
    s.push(ch);//adding that operator
}
    }
     while(!s.empty()){
        postfix=postfix+ s.top();//jo bachge unko add krdiya
        s.pop();
    }
    cout<<"postifx is:"<<postfix<<endl;
}

int main(){
    stack<char>s;
    string str;
    cout<<"enter string:"<<endl;
    cin>>str;
    convert(str);
return 0;
}