#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* previous;
    node* next;
    node(int d){
        data=d;
        next=nullptr;
        previous=nullptr;
    }
};
bool checkpalindrome(node* &head){
    if(head==nullptr || head->next==nullptr){
        return true;
    }
    node* temp=head;
    node* temp1=head->previous;
    while(temp!=temp1 && temp->previous!=temp1){
if(temp->data!=temp1->data){
    return false;
}
    temp=temp->next;
    temp1=temp1->previous;
}
return true;
}
void insertionatend(node* &head, int d) {
    node* temp=new node(d);
    if (head==nullptr) {
        temp->next=temp;
        temp->previous=temp;
        head=temp;
        return;
    }
    temp->next=head;
    temp->previous=head->previous;
    head->previous->next=temp;
    head->previous=temp;
}
void display(node* &head){
    if(head==nullptr){
        return ;
    }
    node* temp=head;
    do{
        cout<<temp->data;
        temp=temp->next;
    }while(temp!=head);
    cout<<head->data<<endl;
}
int main(){
    node* head=nullptr;
    insertionatend(head,10);
     insertionatend(head,20);
      insertionatend(head,30);
       insertionatend(head,20);
        insertionatend(head,10);
        display(head);
        if(checkpalindrome(head)){
            cout<<"yes it is a palindromen"<<endl;
        }
        else{
            cout<<"not a palindrom"<<endl;
        }
        return 0;
}