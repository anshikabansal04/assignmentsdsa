#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        this->data=d;
        this->next=nullptr;
    }
};
   void insertion(node* &head,int d){
node* temp=new node(d);
temp->next=head;
head=temp;
 }
 void display(node* &head){
        node* temp=head;
while(temp!=nullptr){
    cout<<temp->data<<endl;//tc O(n);
    //scO(1);
    temp=temp->next;
}
cout<<endl;
 }  
int findmiddle(node* &head){
node* fast=head->next;
node* slow=head;
while(fast!=nullptr){
    fast=fast->next;
    if(fast!=nullptr){
        fast=fast->next;
    }
    slow=slow->next;
}
return slow->data;
}
int main(){
node* name=new node(4);
node* head=name;
insertion(head,3);
insertion(head,2);
insertion(head,1);
display(head);
int ans=findmiddle(head);
cout<<"middle element is "<<ans<<endl;
return 0;
}