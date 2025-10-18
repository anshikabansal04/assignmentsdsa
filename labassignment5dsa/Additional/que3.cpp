#include<iostream>
#include<map>
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
node* floyd(node* &head){
    if(head==nullptr){
       return nullptr;
    }
    node* slow=head;
    node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        fast=fast->next;
        if(fast!=nullptr){
            fast=fast->next;
        }
        slow=slow->next;
    if(fast==slow){
        cout<<"present at"<<slow->data<<endl;
       return slow;
    }
}
return nullptr;
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
 void insertion(node* &head,int d){
node* temp=new node(d);
temp->next=head;
head=temp;
 }
 node* gettingloopstarting(node* &head){
    if(head==nullptr){
        return nullptr;
    }
    node* intersection=floyd(head);
    if(intersection==nullptr) 
    {
        return nullptr;
    }
    node* slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
 }
 void removeloop(node* &head){
    if(head==nullptr){
        return ;
    }
    node* startofloop=gettingloopstarting(head);
    if(startofloop==nullptr)
     {
        return ;
    }
    node* temp=startofloop;
    while(temp->next!=startofloop){
        temp=temp->next;
    }
     temp->next=nullptr;
 }
int main(){
node* head=nullptr;
insertion(head, 50);
insertion(head, 40);
insertion(head, 30);
insertion(head, 20);
insertion(head, 10);
   node* temp = head;
    node* join = nullptr;
    while(temp->next != nullptr){
        if(temp->data == 30)
         join = temp; 
        temp = temp->next;
    }
    temp->next=join;
if (floyd(head)) {
        cout << "Yes, cycle exists!"<<endl;
        node* start=gettingloopstarting(head);
        cout<<"Cycle starts at node with data "<<start->data<< endl;
        removeloop(head);
        display(head); 
    } else {
        cout <<"No cycle."<< endl;
    }
return 0;
}
