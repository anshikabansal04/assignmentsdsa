#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=nullptr;
    }
};
void splitlist(node* &head,node* &head1,node* &head2){
    if(head==nullptr || head->next==head){
        head1=head;
        head2=nullptr;
        return;
    }
    int t=1;
    node* temp=head;
    while(temp->next!=head){
        t++;
        temp=temp->next;
    }
    int mid;
    if(t%2==0)
    {
         mid=t/2;
        }
    else{ 
        mid=(t/2)+1;
    }
    node* current=head;
    for(int i=1;i<mid;i++){  // fixed off-by-one
        current=current->next;
    }
    head1=head;
    head2=current->next;
    current->next=head1; // make first circular
    temp=head2;
    while(temp->next!=head){ // fixed == error
        temp=temp->next;
    }
    temp->next=head2; // make second circular
}
void insertionatend(node* &head,int d){
    node* temp=new node(d);
    if(head==nullptr){
        head=temp;
        head->next=head;
        return; 
    }
    node* temp2=head;
    while(temp2->next!=head){
        temp2=temp2->next;
    }
    temp2->next=temp;
    temp->next=head;
}
void display(node* head) {
    if (head==nullptr) return;
    node* temp=head;
    do {
        cout<<temp->data<<" ";
        temp=temp->next;
    } while(temp != head);
    cout<<endl;
}
int main(){
    node* head=nullptr;
    insertionatend(head,10);
    insertionatend(head,4);
    insertionatend(head,9);
    insertionatend(head,12);
    insertionatend(head,15);
    cout<<"Original circular list: ";
    display(head);
    node* head1=nullptr;
    node* head2=nullptr;
    splitlist(head,head1,head2);
    cout<<"First half: ";
    display(head1);
    cout<<"Second half: ";
    display(head2);
    return 0;
}
