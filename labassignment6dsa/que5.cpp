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
void  circular(node* &head){
if(head==nullptr){
   cout<<"empty"<<head;
   return ;
}
node* temp=head->next;
    while(temp!=nullptr && temp!=head){
temp=temp->next;
    }
    if(temp==nullptr){
        cout<<"non circular"<<endl;
    }
    if(temp==head){
        cout<<"circular"<<endl;
    }
}
void display(node* &head){
        node* temp=head;
while(temp!=nullptr){
    cout<<temp->data<<endl;
    temp=temp->next;
}
cout<<endl;
 }
int main(){
    node* head=nullptr;
     insertion(head, 3);
    insertion(head, 2);
    insertion(head, 1);
    display(head);
    cout<<"after:"<<endl;
    circular(head);
}