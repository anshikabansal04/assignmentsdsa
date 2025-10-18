#include<iostream>
using namespace std;
class node{
    public:
int data;
node* previous;
node* next;
node(int d){
    data=d;
    previous=nullptr;
    next=nullptr;
}
};
void insertionathead(node* &head,int d){
    node* temp=new node(d);
    if(head==nullptr){
        temp->next=temp;
        temp->previous=temp;
        head=temp;
        return ;
    }
temp->next =head;
temp->previous=head->previous;
head->previous->next=temp;
head->previous=temp;
head=temp;
}
void insertionatend(node* &head,int d)

{
    node* temp=new node(d);
    if(head==nullptr){
         temp->next=temp;
        temp->previous=temp;
        head=temp;
        return ;
    }
temp->next=head;
 temp->previous=head->previous;
head->previous->next=temp;
head->previous=temp;
}
void insertatspecnode(node* &head,int d,int value){
    node* temp=new node(d);
    node* temp1=head;
    while(temp1->next!=head && temp1->data!=value){
    temp1=temp1->next;
}
temp->next=temp1->next;
temp->previous=temp1;
temp1->next->previous=temp;
temp1->next=temp;
}
void   delelteformbeg(node* &head){
    if(head==nullptr){
        cout<<"list is empty"<<endl;
        return ;
    }
 node* temp=head;
if(temp->next==head){
    head=nullptr;
}
else{
head->previous->next=  head->next;
 head->next->previous=head->previous;
head=head->next;
}
delete temp;
}
void   deletefromend(node* &head){
   if(head==nullptr){
        cout<<"list is empty"<<endl;
        return ;
    }
    node* temp=head->previous;
if(temp==head){
    head=nullptr;
}
else{
temp->previous->next=head;
head->previous=temp->previous;
}
    delete temp;
}
void deleterfromspecific(node* &head,int value){
    node* temp=head;
if(head==nullptr){
        cout<<"list is empty"<<endl;
        return ;
    }
    else{
       while(temp->next!=head && temp->data!=value){
temp=temp->next;
       } 
    }
    temp->previous->next=temp->next;
    temp->next->previous=temp->previous;
    delete temp;
}
void search(node* &head, int d) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    node* temp = head;
    do {
        if (temp->data == d) {
            cout << "Node "<<d<<"found!\n";
            return;
        }
        temp=temp->next;
    } while (temp != head);
    cout<<"Node "<<d<<"not found!\n";
}
void display(node* &head){
    if(head==nullptr){
        cout<<"list is empty"<<endl;
    }
    node* temp=head;
    do{
        cout<<temp->data;
        temp=temp->next;
}while(temp!=head);
cout<<endl;
}
int main() {
    node* head = nullptr;
    int choice, data, value;

    do {
     cout<<"\n===== CIRCULAR DOUBLY LINKED LIST MENU =====";
     cout<<"\n1. Insert at Head";
     cout<<"\n2. Insert at End";
     cout<<"\n3. Insert After a Node";
     cout<<"\n4. delete form beg";
     cout<<"\n5. delete at end";
     cout<<"\n6. delelte from a spepcific node";
    cout<<"\n7. search for a node";
  cout<<"\n8. Display List";
     cout<<"\n9. Exit";
     cout<<"\nEnter your choice: ";
     cin>>choice;
     switch (choice) {
 case 1:
      cout<<"Enter data to insert at head: ";
          cin>>data;
         insertionathead(head, data);
            break;
            case 2:
                cout<<"Enter data to insert at end: ";
                cin>>data;
              insertionatend(head, data);
                break;
            case 3:
                cout<<"Enter value after which to insert: ";
                cin>>value;
                cout<<"Enter data to insert: ";
                cin>>data;
 insertatspecnode(head, data,value);
                break;
 case 4:
cout<<"Enter value before which to insert: ";
cin>>value;
cout<<"Enter data to insert: ";
cin>>data;
delelteformbeg(head);
break;
case 5:
 deletefromend(head);
break;
case 6:
 deleterfromspecific(head,data);
 break;
 case 7:
cout<<"node you want to search"<<endl;
cin>>data;
search(head,data);
break;
 case 8:
display(head);
break;
case 9:
 cout << "Exiting...\n";
 break;
 default:
 cout << "Invalid choice!\n";
        }
    } while (choice != 9);

    return 0;
}