#include<iostream>
#include<stdbool.h>
using namespace std;
#define max 100
class node{
    public:
    int data;
    node* next;
    node(int d){
        this->data=d;
        next=nullptr;
    }
};
node* hashs[max]={nullptr};
int getHashIndex(node* ptr) {
return ((unsigned long)ptr) % max;
}
bool detectLoop( node* head) {
 node* temp = head;
while (temp !=nullptr) {
int idx= getHashIndex(temp);
if (hashs[idx]==temp)
return true; // loop detected
hashs[idx]=temp;
temp = temp->next;
}
}
int main(){
  node* head=new node(1);
  head->next=new node(2);
head->next->next = new node(3);
head->next->next->next = new node(4);
head->next->next->next->next = head->next; 
bool ans=detectLoop(head);
if(ans){
    cout<<"true";
}
else{
    cout<<"false";
}
return 0;
}