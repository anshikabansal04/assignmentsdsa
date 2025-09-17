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
    cout<<temp->data<<endl;
    temp=temp->next;
}
cout<<endl;
 }
 void reverse(node* &head){
        node* previous=nullptr;
        node* current=head;
        node* forward=current->next;
        while(current!=nullptr){
            forward=current->next;
            current->next=previous;
             previous=current;
            current =forward;
        }
        head=previous;
    }
int main(){
node* name=new node(4);
node* head=name;
insertion(head,3);
insertion(head,2);
insertion(head,1);
display(head);
reverse(head);
cout<<"after reversing"<<endl;
display(head);
return 0;
}