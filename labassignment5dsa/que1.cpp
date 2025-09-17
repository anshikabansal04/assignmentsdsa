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
 void insertionbeg(node* &head,int d){
node* temp=new node(d);
temp->next=head;
head=temp;
    }
void insertend(node* &head,int d){
 node* temp=new node(d);
 if(head==nullptr){
    head=temp;
    return ;
}
node* ptr=head;
while(ptr->next!=nullptr){
ptr=ptr->next;
}
ptr->next=temp;
} 
void insertbetween(node* head,int pos,int d){
    node* newnode=new node(d);
    int cnt=1;
    node* temp=head;
    while(cnt<pos-1 && temp!=nullptr){
    temp=temp->next;
    cnt++;
}
if(temp==nullptr){
    cout<<"out of range"<<endl;
    delete newnode;
    return ;
}
    newnode->next=temp->next;
    temp->next=newnode;
}
void deletefrombeg(node* &head){
    if (head == nullptr) {
        cout<<"List is empty!"<<endl;
        return;
    }
    node* temp=head;
    head=head->next; 
    delete temp;
}
void delatend(node* head){
    if(head==nullptr){
        cout<<"list is empty"<<endl;
        return ;
    }
    if(head->next==nullptr){
        delete head;
        head=nullptr;
        return;
    }
node* temp=head;
while(temp->next->next!=nullptr){
temp=temp->next;
}
delete temp->next;
temp->next=nullptr;
}
void deltatspeci(node* head,int key){
    if(head==nullptr){
        return ;
    }
    if(head->data==key){
        deletefrombeg(head);
        return ;
    }
    node* temp=head;
     while (temp->next!=nullptr && temp->next->data!= key) {
        temp=temp->next;
    }
    if (temp->next == nullptr) {
        cout<<"Node" <<key<<" not found.\n";
        return;
    }
    node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}
    void display(node* head){
        node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
        cout<<endl;
    }
void search(node* head, int key) {
    node* temp = head;
    int pos=1;
    while (temp != nullptr) {
        if (temp->data == key) {
            cout << "Node "<< key<<" found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout<<"Node "<< key << " not found in the list." << endl;
}
int main(){
    node* head=nullptr;
    int choice,val,key;
    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete a Specific Node (by value)\n";
        cout << "7. Search a Node\n";
        cout << "8. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
               insertionbeg(head,val);
                break;
            case 2:
                cout<<"Enter value: ";
                cin>>val;
               insertend(head, val);
                break;
            case 3:
                cout << "Enter pos: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                insertbetween(head,key,val);
                break;
            case 4:
               deletefrombeg(head);
                break;
            case 5 :
                delatend(head);
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> key;
                deltatspeci(head, key);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> key;
                search(head, key);
                break;
                case 8:
                display(head);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);
    return 0;
}
