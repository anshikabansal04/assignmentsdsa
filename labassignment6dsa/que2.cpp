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
void insertionatend(node* &head, int d) {
    node* temp = new node(d);
    if (head==nullptr) {
        temp->next = temp;
        temp->previous = temp;
        head = temp;
        return;
    }
    temp->next = head;
    temp->previous = head->previous;
    head->previous->next = temp;
    head->previous = temp;
}
int main() {
    node* head = nullptr;
    int choice = 0, data;

    while (choice != 3) {
        cout<<"\nCIRCULAR DOUBLY LINKED LIST MENU =====";
        cout<<"\n1. Insert at End";
        cout<<"\n2. Display List";
        cout<<"\n3. Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        if (choice == 1) {
            cout << "Enter data to insert: ";
            cin >> data;
            insertionatend(head, data);
        }
        else if (choice == 2) {
            cout << "List: ";
            display(head);
        } 
        else if (choice == 3) {
            cout<<"Exiting...\n";
        } 
        else {
            cout<<"Invalid choice!\n";
        }
    }
}