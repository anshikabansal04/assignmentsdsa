#include<iostream>
#include<stack>
using namespace std;
bool isbalanced(string str){
	stack<char>s;
	for(int i=0;i<str.length();i++){
		char ch;
		ch=str[i];
		if (ch == '(' || ch == '{' || ch == '['){
		s.push(ch);}
	else if (ch == ')' || ch == '}' || ch == ']') {
		char top=s.top();
		s.pop();
	 if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
        }
	}
}
return s.empty();
}
int main(){
 string str;
    cout<<"Enter string: ";
    getline(cin,str);
    if (isbalanced(str))
        cout<<"Balanced Parentheses"<<endl;
    else
        cout<<"Not Balanced parenthesis"<<endl;

    return 0;
}
