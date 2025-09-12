#include<iostream>
#include<stack>
using namespace std;
stack<int>s;
int minelement;
void push(int x){
    if(s.empty()){
        s.push(x);
        minelement=x;
    }
    else if(x>=minelement){
        s.push(x);
    }
    else{
        s.push((2*x)-minelement);
        minelement=x;
    }
}
void pop() {
    if (s.empty()) {
        cout << "Stack underflow";
        return;
    }
    int t=s.top();
    s.pop();
    if (t<minelement) {
        minelement=(2*minelement)-t;
    }
}
int top() {
    if (s.empty()) {
        cout << "Stack is empty";
        return -1;
    }
    int t = s.top();
    return (t < minelement)? minelement : t;
}  
int getmin(){
    if(s.empty()){
        cout<<"stack empty"<<endl;
        return -1;
    }
    return minelement;
}
int main(){
  push(10);
    push(180);
   push(1);
   push(5);
  push(11);
        cout<<"current "<<getmin()<<endl;
        pop();
         cout<<"current "<<getmin()<<endl;
        pop();
         cout<<"current "<<getmin()<<endl;
         pop();
         cout<<"current"<<getmin()<<endl;
        return 0;
}
