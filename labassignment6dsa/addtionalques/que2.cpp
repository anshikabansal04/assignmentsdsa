#include<iostream>
using namespace std;
/*
class node{
    public:
    int data;
    node* prev;
    node* next;
    node(int d){
        data=d;
        prev=nullptr;
        next=nullptr;
    }
};
//doubly link list
int count(int n){
    int cnt=0;
    while(n){//n>>1right shifting reducing number of bits
        cnt+=n&1;//checking last bit 1then adding 
        n>>=1;//that are total number of ones
    }
    return cnt;
}
void insertatend(node* &head,int val){
node* newnode=new node(val);
if(head==nullptr){
    head=newnode;
    return ;
}
node* temp=head;
while(temp->next!=nullptr){
    temp=temp->next;
}
temp->next=newnode;
newnode->prev=temp;
}
void printlist(node* head){
    node* current=head;
    while(current!=nullptr){
        cout<<current->data<<endl;
        current=current->next;
    }
}
void remove(node* &head){
    node* current=head;
    while(current!=nullptr){
        int cnts=count(current->data);
if(cnts%2==0){
    node* temp=current;
    if(current->prev)//middle or tail
        current->prev->next=current->next;
    else
        head=current->next;
    if(current->next)
        current->next->prev=current->prev;
current=current->next;
delete temp;//alredy stored in temp
}
else{
    current=current->next;
}
    }
}
int main(){
    node* head=nullptr;
insertatend(head,18);
insertatend(head,15);
insertatend(head,8);
insertatend(head,9);
insertatend(head,14);
remove(head);
printlist(head);
return 0;
}
//circular single link list
*/
class node{
    public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=nullptr;
    }
};
void insertionatend(node* &head,int val){
    node* newnode=new node(val);
    if(head==nullptr){
head=newnode;
head->next=head;
    }
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
}
void printlist(node* head){
    node* temp=head;
    do{
        cout<<temp->data;
        temp=temp->next;
    }while(temp!=head);
}
int count(int n){
    int cnt=0;
    while(n){//n>>1right shifting reducing number of bits
        cnt+=n&1;//checking last bit 1then adding 
        n>>=1;//that are total number of ones
    }
    return cnt;
}
void deleteeven(node* &head){
if(head==nullptr){
    return ;
}
while(head!=nullptr && count(head->data)%2==0){
    if(head->next==head){
        delete head;
        head=nullptr;
        return ;
    }
    node* tail=head;
    while(tail->next!=head){
tail=tail->next;
    }
        node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }
    if (head == NULL)
        return;
   node* curr = head;
    do {
       node* nextnode = curr->next;
        if (count(nextnode->data) % 2 == 0) {
            curr->next=nextnode->next;
            delete nextnode;
        } else {
            curr=curr->next;
        }
    } while (curr->next != head);
}
int main(){
node* head=nullptr;
insertionatend(head,9);
insertionatend(head,11);
insertionatend(head,34);
insertionatend(head,6);
insertionatend(head,13);
insertionatend(head,21);
deleteeven(head);
printlist(head);
return 0;
}
