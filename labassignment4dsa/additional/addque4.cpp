#include<iostream>
#include<queue>
using namespace std;
void countstudent(int students[40],int sanwiches[40],int n){
queue<int>q; 
for(int i=0;i<n;i++){
q.push(students[i]);
}
int ix=0;
int turns=0;
while(!q.empty()&& turns<q.size()){
     if(q.front() == sanwiches[ix]) {
q.pop();
ix++;
turns=0;
     }
     else{
        q.push(q.front());
        q.pop();
        turns++;
     }
}
cout<<q.size()<<endl;
}
int main(){
int students[]={1, 1, 0, 0};
int sandwiches[]={0, 1, 0, 1};
int n=sizeof(students)/sizeof(students[0]);
countstudent(students,sandwiches,n);
return 0;
}
