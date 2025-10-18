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
void insert(node* &head,int d){
    node* newnode=new node(d);
    if(head==nullptr){
      head=newnode;
    }
    else{
        node* temp=head;
        while(temp->next!=nullptr)
                temp=temp->next;
        temp->next=newnode;
    }
}
int  getlength(node* head){
    int l=0;
    node* temp=head;
    while(temp!=nullptr){
        l++;
        temp=temp->next;
    }
return l;
}
int commonnode(node* &head1,node* &head2){
    int l1=getlength(head1);
    int l2=getlength(head2);
    node* ptr1=head1;
    node* ptr2=head2;
    int diff=abs(l1-l2);
    if(l1>l2){
   for(int i=0;i<diff;i++){
    ptr1=ptr1->next;
   }
}
else{
    for(int i=0;i<diff;i++){
        ptr2=ptr2->next;
    }
}
    while(ptr1!=nullptr && ptr2!=nullptr){
        if(ptr1==ptr2){
            return ptr1->data;
        }
            ptr1=ptr1->next;
            ptr2=ptr2->next;
    }
    return -1;
}
int main(){
node* common=new node(7);
    common->next=new node(9);
    node* head1=nullptr;
    insert(head1,3);
    insert(head1,6);
    node* temp=head1;
    while (temp->next!=nullptr)
        temp=temp->next;
    temp->next=common;
    node* head2=nullptr;
    insert(head2,10);
    insert(head2,4);
    temp=head2;
while(temp->next!=nullptr){
    temp=temp->next;
}
 temp->next=common;
    int ans=commonnode(head1, head2);
    if (ans!= -1)
        cout<<"Intersection at node with data: "<<ans<<endl;
    else
        cout<<"No intersection found"<<endl;
    return 0;
}
