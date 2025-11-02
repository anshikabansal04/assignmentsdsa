#include <iostream>
using namespace std;
class node {
    public:
    int data;
    node* prev;
    node* next;
    node* random;
    node(int val) {
        data = val;
        prev=nullptr;
        next=nullptr;
        random=nullptr;
    }
};
void fixRandom(node* head) {
    node* temp = head;
    while (temp && temp->next) {
        node* expected = temp->next;
        if (temp->random != expected) {
            cout << "Wrong random found at node " << temp->data << endl;
            temp->random = expected; 
        }
        temp=temp->next;
    }
}
void printRandom(node* head) {
    node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        if (temp->random)
            cout<<temp->random->data;
        else
            cout<<"NULL";
        cout<<endl;
        temp=temp->next;
    }
}
int main(){
node* head=new node(1);
node* n2=new node(2);
node* n3=new node(3);
node* n4=new node(4);
head->next=n2;
n2->prev=head;
n2->next=n3;
n3->prev=n2;
n3->next=n4;
n4->prev=n3;
head->random=n2;
n2->random=n3;
n3->random=head;
n4->random=nullptr;
cout<<"before fixing"<<endl;
printRandom(head);
fixRandom(head);
printRandom(head);
return 0;
}
