#include<iostream>
using namespace std;
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
node* reverse(node* &head,int k){
    if(head==nullptr){
        return nullptr;
    }
    node* curr=head;
    node* prevnode=nullptr;
    node* nextnode=nullptr;
    int count=0;
      while (curr != NULL && count < k) {
        nextnode = curr->next;  
        curr->next = prevnode;   
        curr->prev = nextnode;  
        prevnode = curr;        
        curr = nextnode;         
        count++;
    }
    if(nextnode!=nullptr){
        head->next=reverse(nextnode,k);
        if(head->next!=nullptr){
            head->next->prev=head;
        }
    }
    return prevnode;
}
int main(){
    node* head=nullptr;
    insertatend(head,1);
    insertatend(head,2);
    insertatend(head,3);
    insertatend(head,4);
    insertatend(head,5);
    insertatend(head,6);
    int k=2;
    node* prevnode=reverse(head,2);
    printlist(prevnode);
}
