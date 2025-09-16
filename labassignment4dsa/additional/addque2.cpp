#include<iostream>
#include<queue>
using namespace std;
void sorted(queue<int>&q2){
int front=0;
int n=q2.size();
for(int i=0;i<n;i++){
    int min=INT_MAX;
 for(int j=0;j<n;j++){//find min
    int val=q2.front();
    q2.pop();
 if(val<min && j<(n-i)){
     min=val;
 }
 q2.push(val);
}
bool skip=false;
for(int j=0;j<n;j++){
    int val=q2.front();
    q2.pop();
    if(j<(n-i) &&val==min && !skip){
        skip=true;
    }
    else{
        q2.push(val);
    }
}
q2.push(min);
}
}
int main(){
    queue<int>q1;
 q1.push(11); 
 q1.push(5);
 q1.push(4);
 q1.push(21);
 sorted(q1);
 while(!q1.empty()){
    cout<<q1.front()<<endl;
   q1.pop();
 }
}
