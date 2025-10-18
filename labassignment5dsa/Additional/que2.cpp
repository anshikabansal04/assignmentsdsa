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
void display(node* &head){
        node* temp=head;
while(temp!=nullptr){
    cout<<temp->data<<endl;
    temp=temp->next;
}
cout<<endl;
 }
 void  insertion(node* &head,int d){
node* temp=new node(d);
temp->next=head;
head=temp;
 }
node* reversek(node* &head,int k){
    node* previous=nullptr;
    node* current=head;
    node* forward=nullptr;
    int count=0;
    int length=0;
    node* check=head;
    while(check!=nullptr && length<k){
        check=check->next;
        length++;
    }
    if(length<k){
        return head;
    }
    while(current!=nullptr && count<k){
     forward=current->next;
    current->next=previous;
    previous=current;
    current=forward;
    count++;
}
    if(forward!=nullptr){
head->next=reversek(forward,k);
    }
    return previous;
 }
int main(){
node* head=nullptr;
insertion(head,6);
    insertion(head,5);
    insertion(head,4);
    insertion(head,3);
    insertion(head,2);
    insertion(head,1);
    cout<<"beforre:"<<endl;
    display(head);
node* ans=reversek(head,2);
cout<<"after"<<endl;
display(ans);
return 0;
}
