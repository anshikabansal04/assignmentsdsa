#include<iostream>
#include<queue>
#include<stack>
using namespace std;
bool possible(queue<int>q){
    int expected=1;
    stack<int>s;
    while(!q.empty()||!s.empty()){
    if(!q.empty() && q.front()==expected){
        q.pop();
        expected++;
    }
    else if(!s.empty() && s.top()==expected){
        s.pop();
        expected++;
    }
    else if(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    else{
        return false;
    }
}
return true;
}
int main(){
queue<int>q;
q.push(5);
q.push(1);
q.push(2);
q.push(3);
q.push(4);
if(possible(q)){
    cout<<"yes"<<endl;
}
else{
    cout<<"no"<<endl;
}
return 0;
}
